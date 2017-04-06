#ifndef FSLSIMPLEUI_LAYOUT_COMPLEXSTACKLAYOUT_HPP
#define FSLSIMPLEUI_LAYOUT_COMPLEXSTACKLAYOUT_HPP
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

#include <FslSimpleUI/Layout/Layout.hpp>
#include <FslSimpleUI/Layout/LayoutOrientation.hpp>
#include <FslSimpleUI/Layout/LayoutLength.hpp>
#include <deque>

namespace Fsl
{
  namespace UI
  {
    class ComplexStackLayout : public Layout
    {
      struct FinalLayout
      {
        LayoutUnitType UnitType;
        float Position;
        float Size;

        FinalLayout()
          : UnitType(LayoutUnitType::Auto)
          , Position(0)
          , Size()
        {
        }
      };

      LayoutOrientation m_orientation;
      std::deque<LayoutLength> m_layoutLength;
      std::deque<FinalLayout> m_finalLayout;
      float m_spacing;

    public:
      ComplexStackLayout(const std::shared_ptr<WindowContext>& context);

      LayoutOrientation GetLayoutOrientation() const { return m_orientation; }
      void SetLayoutOrientation(const LayoutOrientation& value);
      float GetSpacing() const { return m_spacing; }
      void SetSpacing(const float& value);

      void ClearLayoutLengths();
      void PushLayoutLength(const LayoutLength& layoutLength);
      void PopLayoutLength();
    protected:
      virtual Vector2 ArrangeOverride(const Vector2& finalSize) override;
      virtual Vector2 MeasureOverride(const Vector2& availableSize) override;
    private:
      Vector2 CalcFixedStarSizeHorizontal(std::deque<FinalLayout>& rLayoutDefinition, const Vector2& finalSize);
      Vector2 CalcFixedStarSizeVertical(std::deque<FinalLayout>& rLayoutDefinition, const Vector2& finalSize);
      void FinalizeStarSizes(std::deque<FinalLayout>& rLayoutDefinition, const float spaceLeft, const float totalStars);
      void ArrangeHorizontal(const std::deque<FinalLayout>& layoutDefinition, const float finalSizeY);
      void ArrangeVertical(const std::deque<FinalLayout>& layoutDefinition, const float finalSizeX);
    };
  }
}

#endif
