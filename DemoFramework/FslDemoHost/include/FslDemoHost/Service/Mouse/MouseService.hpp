#ifndef FSLDEMOHOST_SERVICE_MOUSE_MOUSESERVICE_HPP
#define FSLDEMOHOST_SERVICE_MOUSE_MOUSESERVICE_HPP
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

#include <FslDemoHost/Service/ThreadLocal/ThreadLocalService.hpp>
#include <FslDemoApp/Service/Mouse/IMouse.hpp>
#include <FslDemoApp/Service/ServiceProvider.hpp>
#include <FslDemoApp/Service/NativeWindowEvents/INativeWindowEventListener.hpp>
#include <FslNativeWindow/VirtualMouseButtonFlags.hpp>

namespace Fsl
{
  class IEventPoster;

  class MouseService
    : public ThreadLocalService
    , public std::enable_shared_from_this<MouseService>
    , public IMouse
    , public INativeWindowEventListener
  {
    VirtualMouseButtonFlags m_buttonState;
    Point2 m_position;
    std::shared_ptr<IEventPoster> m_eventPoster;
  public:
    MouseService(const ServiceProvider& serviceProvider);
    ~MouseService();

    virtual void Link(const ServiceProvider& serviceProvider) override;

    // From IMouse
    virtual MouseState GetState() override;

    // From INativeWindowEventListener
    virtual void OnNativeWindowEvent(const NativeWindowEvent& event) override;
  private:
    void OnMouseButton(const NativeWindowEvent& event);
    void OnMouseMove(const NativeWindowEvent& event);
    void OnMouseWheel(const NativeWindowEvent& event);
  };
}

#endif
