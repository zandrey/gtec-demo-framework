#ifndef FSLSIMPLEUI_CONTROL_CHECKBOX_HPP
#define FSLSIMPLEUI_CONTROL_CHECKBOX_HPP
/****************************************************************************************************************************************************
* Copyright (c) 2015 Freescale Semiconductor, Inc.
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

#include <FslBase/Math/NineSlice.hpp>
#include <FslGraphics/Render/AtlasTexture2D.hpp>
#include <FslSimpleUI/BaseWindow.hpp>
#include <string>

namespace Fsl
{
  class AtlasFont;

  namespace UI
  {

    class CheckBox : public BaseWindow
    {
      std::string m_text;
      std::shared_ptr<AtlasFont> m_font;
      AtlasTexture2D m_texChecked;
      AtlasTexture2D m_texUnchecked;
      bool m_isChecked;
    public:
      CheckBox(const std::shared_ptr<WindowContext>& context);

      const std::shared_ptr<AtlasFont>& GetFont() const { return m_font; }
      void SetFont(const std::shared_ptr<AtlasFont>& value);

      const std::string& GetText() const { return m_text; }
      void SetText(const std::string& value);

      const AtlasTexture2D& GetCheckedTexture() const { return m_texChecked; }
      void SetCheckedTexture(const AtlasTexture2D& value);

      const AtlasTexture2D& GetUncheckedTexture() const { return m_texUnchecked; }
      void SetUncheckedTexture(const AtlasTexture2D& value);

      bool IsChecked() const { return m_isChecked; }
      void SetIsChecked(const bool value);

      void Toggle();

      virtual void WinDraw(const UIDrawContext& context) override;
    protected:
      virtual void OnClickInput(const RoutedEventArgs& args, const std::shared_ptr<WindowInputClickEvent>& theEvent) override;
      virtual Vector2 ArrangeOverride(const Vector2& finalSize) override;
      virtual Vector2 MeasureOverride(const Vector2& availableSize) override;
    };
  }
}

#endif
