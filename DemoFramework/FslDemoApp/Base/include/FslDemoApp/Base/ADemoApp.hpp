#ifndef FSLDEMOAPP_BASE_ADEMOAPP_HPP
#define FSLDEMOAPP_BASE_ADEMOAPP_HPP
/****************************************************************************************************************************************************
 * Copyright (c) 2014 Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *    * Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 *
 *    * Redistributions in binary form must reproduce the above copyright notice,
 *      this list of conditions and the following disclaimer in the documentation
 *      and/or other materials provided with the distribution.
 *
 *    * Neither the name of the Freescale Semiconductor, Inc. nor the names of
 *      its contributors may be used to endorse or promote products derived from
 *      this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************************************************************************************/

#include <FslBase/Math/Pixel/PxExtent2D.hpp>
#include <FslBase/Math/Point2.hpp>
#include <FslDemoApp/Base/DemoAppConfig.hpp>
#include <FslDemoApp/Base/IDemoApp.hpp>
#include <FslDemoApp/Base/Service/Content/IContentManager.hpp>
#include <FslDemoApp/Base/Service/Persistent/IPersistentDataManager.hpp>
#include <FslDemoApp/Base/Service/DemoAppControl/IDemoAppControl.hpp>
#include <FslDemoApp/Base/Service/Events/Basic/KeyEvent.hpp>
#include <FslDemoApp/Base/Service/Events/Basic/MouseButtonEvent.hpp>
#include <FslDemoApp/Base/Service/Events/Basic/MouseMoveEvent.hpp>
#include <FslDemoApp/Base/Service/Events/Basic/MouseWheelEvent.hpp>
#include <FslDemoApp/Base/Service/Events/Basic/RawMouseMoveEvent.hpp>
#include <FslDemoApp/Base/Service/Events/Basic/TimeStateEvent.hpp>
#include <memory>

namespace Fsl
{
  class DemoAppExtension;

  class ADemoApp : public IDemoApp
  {
  protected:
    enum class ObjectLifeCycle
    {
      Constructing,
      Constructed,
      Destroyed
    };

  private:
    DemoAppConfig m_demoAppConfig;
    std::weak_ptr<IContentManager> m_contentManger;
    std::weak_ptr<IPersistentDataManager> m_persistentDataManager;
    std::weak_ptr<IDemoAppControl> m_demoAppControl;
    std::deque<std::weak_ptr<DemoAppExtension>> m_extensions;
    ObjectLifeCycle m_currentLifeCycleState = ObjectLifeCycle::Constructing;

  public:
    explicit ADemoApp(const DemoAppConfig& demoAppConfig);
    ~ADemoApp() override;
    void _PostConstruct() override;
    void _PreDestruct() override;
    void _OnEvent(IEvent* const pEvent) override;
    void _ConfigurationChanged(const DemoWindowMetrics& windowMetrics) override;
    void _PreUpdate(const DemoTime& demoTime) override;
    void _FixedUpdate(const DemoTime& demoTime) override;
    void _Update(const DemoTime& demoTime) override;
    void _PostUpdate(const DemoTime& demoTime) override;
    AppDrawResult _TryPrepareDraw(const DemoTime& demoTime) override;
    void _Draw(const DemoTime& demoTime) override;
    AppDrawResult _TrySwapBuffers(const DemoTime& demoTime) override;

  protected:
    // Overload these methods instead of the original IDemoApp ones!

    //! @brief Called just after the object has been successfully constructed
    virtual void OnConstructed()
    {
    }

    //! @brief Called just before the object is destroyed.
    //!        This allows having shutdown code the rely on virtual methods and limited exception support.
    //!        So this should really be the preferred location to put shutdown code instead of using the destructor!
    virtual void OnDestroy()
    {
    }

    virtual void OnKeyEvent(const KeyEvent& event)
    {
      FSL_PARAM_NOT_USED(event);
    }

    virtual void OnMouseButtonEvent(const MouseButtonEvent& event)
    {
      FSL_PARAM_NOT_USED(event);
    }

    virtual void OnMouseMoveEvent(const MouseMoveEvent& event)
    {
      FSL_PARAM_NOT_USED(event);
    }

    virtual void OnMouseWheelEvent(const MouseWheelEvent& event)
    {
      FSL_PARAM_NOT_USED(event);
    }

    virtual void OnTimeStateEvent(const TimeStateEvent& event)
    {
      FSL_PARAM_NOT_USED(event);
    }

    virtual void OnRawMouseMoveEvent(const RawMouseMoveEvent& event)
    {
      FSL_PARAM_NOT_USED(event);
    }

    virtual void ConfigurationChanged(const DemoWindowMetrics& windowMetrics)
    {
      FSL_PARAM_NOT_USED(windowMetrics);
    }


    virtual void PreUpdate(const DemoTime& demoTime)
    {
      FSL_PARAM_NOT_USED(demoTime);
    }

    virtual void FixedUpdate(const DemoTime& demoTime)
    {
      FSL_PARAM_NOT_USED(demoTime);
    }

    virtual void Update(const DemoTime& demoTime)
    {
      FSL_PARAM_NOT_USED(demoTime);
    }

    virtual void PostUpdate(const DemoTime& demoTime)
    {
      FSL_PARAM_NOT_USED(demoTime);
    }

    virtual void Draw(const DemoTime& demoTime)
    {
      FSL_PARAM_NOT_USED(demoTime);
    }

    virtual AppDrawResult TryPrepareDraw(const DemoTime& demoTime)
    {
      FSL_PARAM_NOT_USED(demoTime);
      return AppDrawResult::Completed;
    }

    //! @note This will only be called if the DemoHost delegates SwapBuffers to the app (most dont).
    virtual AppDrawResult TrySwapBuffers(const DemoTime& demoTime)
    {
      FSL_PARAM_NOT_USED(demoTime);
      throw NotSupportedException("TrySwapBuffers");
    }

    //! @brief Register a demo app extension
    void RegisterExtension(const std::shared_ptr<DemoAppExtension>& extension);
    void UnregisterExtension(const std::shared_ptr<DemoAppExtension>& extension);

    //! @brief Get the current window metrics
    const DemoWindowMetrics& GetWindowMetrics() const
    {
      return m_demoAppConfig.WindowMetrics;
    }

    //! @brief Get the size of the window client area in pixels.
    PxSize2D GetWindowSizePx() const;

    //! @brief Get the aspect ratio of the window
    float GetWindowAspectRatio() const;

    //! @brief Get the current screen resolution
    [[deprecated("use GetWindowSizePx instead")]] const Point2& GetScreenResolution() const
    {
      return m_demoAppConfig.ScreenResolution;
    }

    const PxExtent2D& GetScreenExtent() const
    {
      return m_demoAppConfig.WindowMetrics.ExtentPx;
    }

    //! @brief Get access to the demo app control interface
    std::shared_ptr<IDemoAppControl> GetDemoAppControl() const;
    //! @brief Access the content manager;
    std::shared_ptr<IContentManager> GetContentManager() const;
    //! @brief Access the Persistent Data Manager;
    std::shared_ptr<IPersistentDataManager> GetPersistentDataManager() const;

    const ExceptionMessageFormatter& GetExceptionFormatter() const;

    ObjectLifeCycle GetObjectLifeCycleState() const
    {
      return m_currentLifeCycleState;
    }

  private:
    void UnhandledKeyFallback(const KeyEvent& keyEvent);
  };
}

#endif
