#ifndef FSLSIMPLEUI_BASE_CONTROL_BASICIMAGE_HPP
#define FSLSIMPLEUI_BASE_CONTROL_BASICIMAGE_HPP
/****************************************************************************************************************************************************
 * Copyright 2020 NXP
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
 *    * Neither the name of the NXP. nor the names of
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

#include <FslGraphics/Color.hpp>
#include <FslSimpleUI/Base/BaseWindow.hpp>
#include <FslSimpleUI/Base/ItemScalePolicy.hpp>
#include <memory>

namespace Fsl
{
  class BasicImageSprite;

  namespace UI
  {
    class WindowContext;

    //! @brief This is the recommended image control. It is DP aware so it will render the image so it fits the users display.
    class BasicImage : public BaseWindow
    {
    protected:
      const std::shared_ptr<WindowContext> m_windowContext;

    private:
      std::shared_ptr<BasicImageSprite> m_content;
      Color m_contentColor{Color::White()};
      ItemScalePolicy m_scalePolicy;

    public:
      explicit BasicImage(const std::shared_ptr<WindowContext>& context);

      const std::shared_ptr<BasicImageSprite>& GetContent() const
      {
        return m_content;
      }

      void SetContent(const std::shared_ptr<BasicImageSprite>& value);
      void SetContent(std::shared_ptr<BasicImageSprite>&& value);

      Color GetContentColor() const
      {
        return m_contentColor;
      }

      void SetContentColor(const Color& value);

      ItemScalePolicy GetScalePolicy() const
      {
        return m_scalePolicy;
      }

      void SetScalePolicy(const ItemScalePolicy value);

      void WinDraw(const UIDrawContext& context) override;

    protected:
      PxSize2D ArrangeOverride(const PxSize2D& finalSizePx) override;
      PxSize2D MeasureOverride(const PxAvailableSize& availableSizePx) override;
    };
  }
}

#endif
