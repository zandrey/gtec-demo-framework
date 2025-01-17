/****************************************************************************************************************************************************
 * Copyright 2018 NXP
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

// Make sure Common.hpp is the first include file (to make the error message as helpful as possible when disabled)
#include <FslUtil/Vulkan1_0/Common.hpp>
#include <FslUtil/Vulkan1_0/Native/NativeBatch2D.hpp>
#include <FslGraphics/Render/AtlasTexture2D.hpp>
#include <FslGraphics/Render/Texture2D.hpp>
#include <FslGraphics/Render/Adapter/INativeTexture2D.hpp>
#include <FslGraphics/Sprite/Material/ISpriteMaterial.hpp>
#include <FslGraphics/Sprite/Font/SpriteFont.hpp>
#include <FslUtil/Vulkan1_0/Native/ANativeTexture2D.hpp>
#include <FslUtil/Vulkan1_0/Native/DynamicNativeTexture2D.hpp>
#include <FslUtil/Vulkan1_0/Native/NativeTexture2D.hpp>

namespace Fsl
{
  namespace Vulkan
  {
    NativeBatch2D::NativeBatch2D(const std::shared_ptr<QuadBatch>& quadRenderer, const PxExtent2D& currentExtent)
      : Batch2D(quadRenderer, currentExtent)
    {
    }

    // ---------- 0

    void NativeBatch2D::Draw(const INativeTexture2D& srcTexture, const NativeTextureArea& srcArea, const PxAreaRectangleF& dstRectanglePxf,
                             const Color& color)
    {
      const auto& nativeTex = dynamic_cast<const ANativeTexture2D&>(srcTexture);

      Batch2D::Draw(nativeTex.ToTextureInfo(), srcArea, dstRectanglePxf, color);
    }

    void NativeBatch2D::Draw(const INativeTexture2D& srcTexture, const NativeTextureArea& srcArea, const PxAreaRectangleF& dstRectanglePxf,
                             const Vector4& color)
    {
      const auto& nativeTex = dynamic_cast<const ANativeTexture2D&>(srcTexture);

      Batch2D::Draw(nativeTex.ToTextureInfo(), srcArea, dstRectanglePxf, color);
    }

    void NativeBatch2D::Draw(const INativeTexture2D& srcTexture, const NativeQuadTextureCoords& srcArea, const PxAreaRectangleF& dstRectanglePxf,
                             const Color& color)
    {
      const auto& nativeTex = dynamic_cast<const ANativeTexture2D&>(srcTexture);

      Batch2D::Draw(nativeTex.ToTextureInfo(), srcArea, dstRectanglePxf, color);
    }

    void NativeBatch2D::Draw(const INativeTexture2D& srcTexture, const NativeQuadTextureCoords& srcArea, const PxAreaRectangleF& dstRectanglePxf,
                             const Vector4& color)
    {
      const auto& nativeTex = dynamic_cast<const ANativeTexture2D&>(srcTexture);

      Batch2D::Draw(nativeTex.ToTextureInfo(), srcArea, dstRectanglePxf, color);
    }


    // ---------- 0 with clip

    void NativeBatch2D::Draw(const INativeTexture2D& srcTexture, const NativeTextureArea& srcArea, const PxAreaRectangleF& dstRectanglePxf,
                             const Color& color, const PxClipRectangle& clipRectPx)
    {
      const auto& nativeTex = dynamic_cast<const ANativeTexture2D&>(srcTexture);

      Batch2D::Draw(nativeTex.ToTextureInfo(), srcArea, dstRectanglePxf, color, clipRectPx);
    }

    void NativeBatch2D::Draw(const INativeTexture2D& srcTexture, const NativeTextureArea& srcArea, const PxAreaRectangleF& dstRectanglePxf,
                             const Vector4& color, const PxClipRectangle& clipRectPx)
    {
      const auto& nativeTex = dynamic_cast<const ANativeTexture2D&>(srcTexture);

      Batch2D::Draw(nativeTex.ToTextureInfo(), srcArea, dstRectanglePxf, color, clipRectPx);
    }

    void NativeBatch2D::Draw(const INativeTexture2D& srcTexture, const NativeQuadTextureCoords& srcArea, const PxAreaRectangleF& dstRectanglePxf,
                             const Color& color, const PxClipRectangle& clipRectPx)
    {
      const auto& nativeTex = dynamic_cast<const ANativeTexture2D&>(srcTexture);

      Batch2D::Draw(nativeTex.ToTextureInfo(), srcArea, dstRectanglePxf, color, clipRectPx);
    }

    void NativeBatch2D::Draw(const INativeTexture2D& srcTexture, const NativeQuadTextureCoords& srcArea, const PxAreaRectangleF& dstRectanglePxf,
                             const Vector4& color, const PxClipRectangle& clipRectPx)
    {
      const auto& nativeTex = dynamic_cast<const ANativeTexture2D&>(srcTexture);

      Batch2D::Draw(nativeTex.ToTextureInfo(), srcArea, dstRectanglePxf, color, clipRectPx);
    }

    // ---------- 1

    void NativeBatch2D::Draw(const AtlasTexture2D& srcTexture, const Vector2& dstPositionPxf, const Color& color)
    {
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(srcTexture.TryGetNativePointer());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }

      Batch2D::Draw(Batch2D::atlas_texture_type(pNativeTex->ToTextureInfo(), srcTexture.GetInfo()), dstPositionPxf, color);
    }


    void NativeBatch2D::Draw(const BaseTexture2D& srcTexture, const Vector2& dstPositionPxf, const Color& color)
    {
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(srcTexture.TryGetNativePointer());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }

      Batch2D::Draw(Batch2D::texture_type(pNativeTex->Get(), srcTexture.GetSize()), dstPositionPxf, color);
    }


    void NativeBatch2D::Draw(const AtlasTexture2D& srcTexture, const PxRectangle& dstRectanglePx, const Color& color)
    {
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(srcTexture.TryGetNativePointer());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }

      Batch2D::Draw(Batch2D::atlas_texture_type(pNativeTex->ToTextureInfo(), srcTexture.GetInfo()), dstRectanglePx, color);
    }


    void NativeBatch2D::Draw(const BaseTexture2D& srcTexture, const PxRectangle& dstRectanglePx, const Color& color)
    {
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(srcTexture.TryGetNativePointer());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }

      Batch2D::Draw(Batch2D::texture_type(pNativeTex->Get(), srcTexture.GetSize()), dstRectanglePx, color);
    }


    void NativeBatch2D::Draw(const AtlasTexture2D& srcTexture, const PxAreaRectangleF& dstRectanglePxf, const Color& color)
    {
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(srcTexture.TryGetNativePointer());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }

      Batch2D::Draw(Batch2D::atlas_texture_type(pNativeTex->ToTextureInfo(), srcTexture.GetInfo()), dstRectanglePxf, color);
    }


    void NativeBatch2D::Draw(const BaseTexture2D& srcTexture, const PxAreaRectangleF& dstRectanglePxf, const Color& color)
    {
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(srcTexture.TryGetNativePointer());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }

      Batch2D::Draw(Batch2D::texture_type(pNativeTex->Get(), srcTexture.GetSize()), dstRectanglePxf, color);
    }


    void NativeBatch2D::Draw(const AtlasTexture2D& srcTexture, const PxAreaRectangleF& dstRectanglePxf, const Color& color, const BatchEffect effect)
    {
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(srcTexture.TryGetNativePointer());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }

      Batch2D::Draw(Batch2D::atlas_texture_type(pNativeTex->ToTextureInfo(), srcTexture.GetInfo()), dstRectanglePxf, color, effect);
    }


    void NativeBatch2D::Draw(const BaseTexture2D& srcTexture, const PxAreaRectangleF& dstRectanglePxf, const Color& color, const BatchEffect effect)
    {
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(srcTexture.TryGetNativePointer());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }

      Batch2D::Draw(Batch2D::texture_type(pNativeTex->Get(), srcTexture.GetSize()), dstRectanglePxf, color, effect);
    }

    // ---------- 2

    void NativeBatch2D::Draw(const AtlasTexture2D& srcTexture, const Vector2& dstPositionPxf, const PxRectangleU& srcRectanglePx, const Color& color)
    {
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(srcTexture.TryGetNativePointer());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }

      Batch2D::Draw(Batch2D::atlas_texture_type(pNativeTex->ToTextureInfo(), srcTexture.GetInfo()), dstPositionPxf, srcRectanglePx, color);
    }


    void NativeBatch2D::Draw(const BaseTexture2D& srcTexture, const Vector2& dstPositionPxf, const PxRectangleU& srcRectanglePx, const Color& color)
    {
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(srcTexture.TryGetNativePointer());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }

      Batch2D::Draw(Batch2D::texture_type(pNativeTex->Get(), srcTexture.GetSize()), dstPositionPxf, srcRectanglePx, color);
    }

    // ---------- 2 with clip

    void NativeBatch2D::Draw(const AtlasTexture2D& srcTexture, const Vector2& dstPositionPxf, const PxRectangleU& srcRectanglePx, const Color& color,
                             const PxClipRectangle& clipRectPx)
    {
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(srcTexture.TryGetNativePointer());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }

      Batch2D::Draw(Batch2D::atlas_texture_type(pNativeTex->ToTextureInfo(), srcTexture.GetInfo()), dstPositionPxf, srcRectanglePx, color,
                    clipRectPx);
    }


    void NativeBatch2D::Draw(const BaseTexture2D& srcTexture, const Vector2& dstPositionPxf, const PxRectangleU& srcRectanglePx, const Color& color,
                             const PxClipRectangle& clipRectPx)
    {
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(srcTexture.TryGetNativePointer());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }

      Batch2D::Draw(Batch2D::texture_type(pNativeTex->Get(), srcTexture.GetSize()), dstPositionPxf, srcRectanglePx, color, clipRectPx);
    }

    // ---------- 2A

    void NativeBatch2D::Draw(const AtlasTexture2D& srcTexture, const Vector2& dstPositionPxf, const PxRectangleU& srcRectanglePx, const Color& color,
                             const BatchEffect effect)
    {
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(srcTexture.TryGetNativePointer());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }

      Batch2D::Draw(Batch2D::atlas_texture_type(pNativeTex->ToTextureInfo(), srcTexture.GetInfo()), dstPositionPxf, srcRectanglePx, color, effect);
    }


    void NativeBatch2D::Draw(const BaseTexture2D& srcTexture, const Vector2& dstPositionPxf, const PxRectangleU& srcRectanglePx, const Color& color,
                             const BatchEffect effect)
    {
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(srcTexture.TryGetNativePointer());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }

      Batch2D::Draw(Batch2D::texture_type(pNativeTex->Get(), srcTexture.GetSize()), dstPositionPxf, srcRectanglePx, color, effect);
    }

    // ---------- 3

    void NativeBatch2D::Draw(const AtlasTexture2D& srcTexture, const PxRectangle& dstRectanglePx, const PxRectangleU& srcRectanglePx,
                             const Color& color)
    {
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(srcTexture.TryGetNativePointer());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }

      Batch2D::Draw(Batch2D::atlas_texture_type(pNativeTex->ToTextureInfo(), srcTexture.GetInfo()), dstRectanglePx, srcRectanglePx, color);
    }

    void NativeBatch2D::Draw(const BaseTexture2D& srcTexture, const PxRectangle& dstRectanglePx, const PxRectangleU& srcRectanglePx,
                             const Color& color)
    {
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(srcTexture.TryGetNativePointer());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }

      Batch2D::Draw(Batch2D::texture_type(pNativeTex->Get(), srcTexture.GetSize()), dstRectanglePx, srcRectanglePx, color);
    }

    // ---------- 4

    void NativeBatch2D::Draw(const AtlasTexture2D& srcTexture, const PxAreaRectangleF& dstRectanglePxf, const PxRectangleU& srcRectanglePx,
                             const Color& color)
    {
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(srcTexture.TryGetNativePointer());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }

      Batch2D::Draw(Batch2D::atlas_texture_type(pNativeTex->ToTextureInfo(), srcTexture.GetInfo()), dstRectanglePxf, srcRectanglePx, color);
    }

    void NativeBatch2D::Draw(const BaseTexture2D& srcTexture, const PxAreaRectangleF& dstRectanglePxf, const PxRectangleU& srcRectanglePx,
                             const Color& color)
    {
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(srcTexture.TryGetNativePointer());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }

      Batch2D::Draw(Batch2D::texture_type(pNativeTex->Get(), srcTexture.GetSize()), dstRectanglePxf, srcRectanglePx, color);
    }

    // ---------- 4 with clip


    void NativeBatch2D::Draw(const AtlasTexture2D& srcTexture, const PxAreaRectangleF& dstRectanglePxf, const PxRectangleU& srcRectanglePx,
                             const Color& color, const PxClipRectangle& clipRectPx)
    {
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(srcTexture.TryGetNativePointer());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }

      Batch2D::Draw(Batch2D::atlas_texture_type(pNativeTex->ToTextureInfo(), srcTexture.GetInfo()), dstRectanglePxf, srcRectanglePx, color,
                    clipRectPx);
    }

    void NativeBatch2D::Draw(const BaseTexture2D& srcTexture, const PxAreaRectangleF& dstRectanglePxf, const PxRectangleU& srcRectanglePx,
                             const Color& color, const PxClipRectangle& clipRectPx)
    {
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(srcTexture.TryGetNativePointer());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }

      Batch2D::Draw(Batch2D::texture_type(pNativeTex->Get(), srcTexture.GetSize()), dstRectanglePxf, srcRectanglePx, color, clipRectPx);
    }


    // ---------- 4A

    void NativeBatch2D::Draw(const AtlasTexture2D& srcTexture, const PxAreaRectangleF& dstRectanglePxf, const PxRectangleU& srcRectanglePx,
                             const Color& color, const BatchEffect effect)
    {
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(srcTexture.TryGetNativePointer());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }

      Batch2D::Draw(Batch2D::atlas_texture_type(pNativeTex->ToTextureInfo(), srcTexture.GetInfo()), dstRectanglePxf, srcRectanglePx, color, effect);
    }

    void NativeBatch2D::Draw(const BaseTexture2D& srcTexture, const PxAreaRectangleF& dstRectanglePxf, const PxRectangleU& srcRectanglePx,
                             const Color& color, const BatchEffect effect)
    {
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(srcTexture.TryGetNativePointer());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }

      Batch2D::Draw(Batch2D::texture_type(pNativeTex->Get(), srcTexture.GetSize()), dstRectanglePxf, srcRectanglePx, color, effect);
    }


    // ---------- 5

    void NativeBatch2D::Draw(const AtlasTexture2D& srcTexture, const Vector2& dstPositionPxf, const Color& color, const Vector2& origin,
                             const Vector2& scale)
    {
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(srcTexture.TryGetNativePointer());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }

      Batch2D::Draw(Batch2D::atlas_texture_type(pNativeTex->ToTextureInfo(), srcTexture.GetInfo()), dstPositionPxf, color, origin, scale);
    }


    void NativeBatch2D::Draw(const BaseTexture2D& srcTexture, const Vector2& dstPositionPxf, const Color& color, const Vector2& origin,
                             const Vector2& scale)
    {
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(srcTexture.TryGetNativePointer());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }


      Batch2D::Draw(Batch2D::texture_type(pNativeTex->Get(), srcTexture.GetSize()), dstPositionPxf, color, origin, scale);
    }

    // ---------- 6

    void NativeBatch2D::Draw(const AtlasTexture2D& srcTexture, const Vector2& dstPositionPxf, const Color& color, const float rotation,
                             const Vector2& origin, const Vector2& scale)
    {
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(srcTexture.TryGetNativePointer());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }

      Batch2D::Draw(Batch2D::atlas_texture_type(pNativeTex->ToTextureInfo(), srcTexture.GetInfo()), dstPositionPxf, color, rotation, origin, scale);
    }


    void NativeBatch2D::Draw(const BaseTexture2D& srcTexture, const Vector2& dstPositionPxf, const Color& color, const float rotation,
                             const Vector2& origin, const Vector2& scale)
    {
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(srcTexture.TryGetNativePointer());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }


      Batch2D::Draw(Batch2D::texture_type(pNativeTex->Get(), srcTexture.GetSize()), dstPositionPxf, color, rotation, origin, scale);
    }

    // ---------- 7

    void NativeBatch2D::Draw(const AtlasTexture2D& srcTexture, const Vector2& dstPositionPxf, const PxRectangleU& srcRectanglePx, const Color& color,
                             const Vector2& origin, const Vector2& scale)
    {
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(srcTexture.TryGetNativePointer());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }

      Batch2D::Draw(Batch2D::atlas_texture_type(pNativeTex->ToTextureInfo(), srcTexture.GetInfo()), dstPositionPxf, srcRectanglePx, color, origin,
                    scale);
    }

    void NativeBatch2D::Draw(const BaseTexture2D& srcTexture, const Vector2& dstPositionPxf, const PxRectangleU& srcRectanglePx, const Color& color,
                             const Vector2& origin, const Vector2& scale)
    {
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(srcTexture.TryGetNativePointer());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }


      Batch2D::Draw(Batch2D::texture_type(pNativeTex->Get(), srcTexture.GetSize()), dstPositionPxf, srcRectanglePx, color, origin, scale);
    }

    // ---------- 7 with clip

    void NativeBatch2D::Draw(const AtlasTexture2D& srcTexture, const Vector2& dstPositionPxf, const PxRectangleU& srcRectanglePx, const Color& color,
                             const Vector2& origin, const Vector2& scale, const PxClipRectangle& clipRectPx)
    {
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(srcTexture.TryGetNativePointer());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }

      Batch2D::Draw(Batch2D::atlas_texture_type(pNativeTex->ToTextureInfo(), srcTexture.GetInfo()), dstPositionPxf, srcRectanglePx, color, origin,
                    scale, clipRectPx);
    }

    void NativeBatch2D::Draw(const BaseTexture2D& srcTexture, const Vector2& dstPositionPxf, const PxRectangleU& srcRectanglePx, const Color& color,
                             const Vector2& origin, const Vector2& scale, const PxClipRectangle& clipRectPx)
    {
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(srcTexture.TryGetNativePointer());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }


      Batch2D::Draw(Batch2D::texture_type(pNativeTex->Get(), srcTexture.GetSize()), dstPositionPxf, srcRectanglePx, color, origin, scale, clipRectPx);
    }

    // ---------- 8

    void NativeBatch2D::Draw(const AtlasTexture2D& srcTexture, const Vector2& dstPositionPxf, const PxRectangleU& srcRectanglePx, const Color& color,
                             const float rotation, const Vector2& origin, const Vector2& scale)
    {
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(srcTexture.TryGetNativePointer());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }

      Batch2D::Draw(Batch2D::atlas_texture_type(pNativeTex->ToTextureInfo(), srcTexture.GetInfo()), dstPositionPxf, srcRectanglePx, color, rotation,
                    origin, scale);
    }

    void NativeBatch2D::Draw(const BaseTexture2D& srcTexture, const Vector2& dstPositionPxf, const PxRectangleU& srcRectanglePx, const Color& color,
                             const float rotation, const Vector2& origin, const Vector2& scale)
    {
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(srcTexture.TryGetNativePointer());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }


      Batch2D::Draw(Batch2D::texture_type(pNativeTex->Get(), srcTexture.GetSize()), dstPositionPxf, srcRectanglePx, color, rotation, origin, scale);
    }

    // ---------- 9

    void NativeBatch2D::Draw(const AtlasTexture2D& srcTexture, const Vector2* const pDstPositions, const int32_t dstPositionsLength,
                             const Color& color)
    {
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(srcTexture.TryGetNativePointer());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }

      Batch2D::Draw(Batch2D::atlas_texture_type(pNativeTex->ToTextureInfo(), srcTexture.GetInfo()), pDstPositions, dstPositionsLength, color);
    }


    void NativeBatch2D::Draw(const BaseTexture2D& srcTexture, const Vector2* const pDstPositions, const int32_t dstPositionsLength,
                             const Color& color)
    {
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(srcTexture.TryGetNativePointer());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }

      Batch2D::Draw(Batch2D::texture_type(pNativeTex->Get(), srcTexture.GetSize()), pDstPositions, dstPositionsLength, color);
    }

    // ---------- 10

    void NativeBatch2D::Draw(const AtlasTexture2D& srcTexture, const Vector2* const pDstPositions, const int32_t dstPositionsLength,
                             const PxRectangleU& srcRectanglePx, const Color& color)
    {
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(srcTexture.TryGetNativePointer());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }

      Batch2D::Draw(Batch2D::atlas_texture_type(pNativeTex->ToTextureInfo(), srcTexture.GetInfo()), pDstPositions, dstPositionsLength, srcRectanglePx,
                    color);
    }


    void NativeBatch2D::Draw(const BaseTexture2D& srcTexture, const Vector2* const pDstPositions, const int32_t dstPositionsLength,
                             const PxRectangleU& srcRectanglePx, const Color& color)
    {
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(srcTexture.TryGetNativePointer());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }

      Batch2D::Draw(Batch2D::texture_type(pNativeTex->Get(), srcTexture.GetSize()), pDstPositions, dstPositionsLength, srcRectanglePx, color);
    }

    // ---------- 11

    void NativeBatch2D::DrawString(const BaseTexture2D& srcTexture, const TextureAtlasBitmapFont& font, const StringViewLite& strView,
                                   const Vector2& dstPositionPxf, const Color& color)
    {
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(srcTexture.TryGetNativePointer());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }

      Batch2D::DrawString(Batch2D::texture_type(pNativeTex->Get(), srcTexture.GetSize()), font, strView, dstPositionPxf, color);
    }

    // ---------- 12

    void NativeBatch2D::DrawString(const BaseTexture2D& srcTexture, const TextureAtlasBitmapFont& font, const StringViewLite& strView,
                                   const Vector2& dstPositionPxf, const Color& color, const Vector2& origin, const Vector2& scale)
    {
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(srcTexture.TryGetNativePointer());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }

      Batch2D::DrawString(Batch2D::texture_type(pNativeTex->Get(), srcTexture.GetSize()), font, strView, dstPositionPxf, color, origin, scale);
    }

    // ---------- 13

    void NativeBatch2D::DrawString(const BaseTexture2D& srcTexture, const TextureAtlasBitmapFont& font, const BitmapFontConfig& fontConfig,
                                   const StringViewLite& strView, const Vector2& dstPositionPxf, const Color& color)
    {
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(srcTexture.TryGetNativePointer());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }

      Batch2D::DrawString(Batch2D::texture_type(pNativeTex->Get(), srcTexture.GetSize()), font, fontConfig, strView, dstPositionPxf, color);
    }

    // ---------- 13 with clip

    void NativeBatch2D::DrawString(const BaseTexture2D& srcTexture, const TextureAtlasBitmapFont& font, const BitmapFontConfig& fontConfig,
                                   const StringViewLite& strView, const Vector2& dstPositionPxf, const Color& color,
                                   const PxClipRectangle& clipRectPx)
    {
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(srcTexture.TryGetNativePointer());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }

      Batch2D::DrawString(Batch2D::texture_type(pNativeTex->Get(), srcTexture.GetSize()), font, fontConfig, strView, dstPositionPxf, color,
                          clipRectPx);
    }

    // ---------- 14

    void NativeBatch2D::DrawString(const BaseTexture2D& srcTexture, const TextureAtlasBitmapFont& font, const BitmapFontConfig& fontConfig,
                                   const StringViewLite& strView, const Vector2& dstPositionPxf, const Color& color, const Vector2& origin,
                                   const Vector2& scale)
    {
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(srcTexture.TryGetNativePointer());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }

      Batch2D::DrawString(Batch2D::texture_type(pNativeTex->Get(), srcTexture.GetSize()), font, fontConfig, strView, dstPositionPxf, color, origin,
                          scale);
    }

    // ---------- 14 with clip

    void NativeBatch2D::DrawString(const BaseTexture2D& srcTexture, const TextureAtlasBitmapFont& font, const BitmapFontConfig& fontConfig,
                                   const StringViewLite& strView, const Vector2& dstPositionPxf, const Color& color, const Vector2& origin,
                                   const Vector2& scale, const PxClipRectangle& clipRectPx)
    {
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(srcTexture.TryGetNativePointer());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }

      Batch2D::DrawString(Batch2D::texture_type(pNativeTex->Get(), srcTexture.GetSize()), font, fontConfig, strView, dstPositionPxf, color, origin,
                          scale, clipRectPx);
    }

    // ---------- 15

    void NativeBatch2D::DrawString(const SpriteFont& font, const StringViewLite& strView, const Vector2& dstPositionPxf, const Color& color)
    {
      const auto& fontInfo = font.GetInfo();
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(fontInfo.MaterialInfo.Material.get());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }

      Batch2D::DrawString(Batch2D::texture_type(pNativeTex->Get(), fontInfo.MaterialInfo.ExtentPx), font.GetAtlasBitmapFont(), fontInfo.FontConfig,
                          strView, dstPositionPxf, color);
    }

    // ---------- 15 with clip

    void NativeBatch2D::DrawString(const SpriteFont& font, const StringViewLite& strView, const Vector2& dstPositionPxf, const Color& color,
                                   const PxClipRectangle& clipRectPx)
    {
      const auto& fontInfo = font.GetInfo();
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(fontInfo.MaterialInfo.Material.get());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }

      Batch2D::DrawString(Batch2D::texture_type(pNativeTex->Get(), fontInfo.MaterialInfo.ExtentPx), font.GetAtlasBitmapFont(), fontInfo.FontConfig,
                          strView, dstPositionPxf, color, clipRectPx);
    }

    // ---------- 16

    void NativeBatch2D::DrawString(const SpriteFont& font, const StringViewLite& strView, const Vector2& dstPositionPxf, const Color& color,
                                   const Vector2& origin, const Vector2& scale)
    {
      const auto& fontInfo = font.GetInfo();
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(fontInfo.MaterialInfo.Material.get());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }

      Batch2D::DrawString(Batch2D::texture_type(pNativeTex->Get(), fontInfo.MaterialInfo.ExtentPx), font.GetAtlasBitmapFont(), fontInfo.FontConfig,
                          strView, dstPositionPxf, color, origin, scale);
    }

    // ---------- 16 with clip

    void NativeBatch2D::DrawString(const SpriteFont& font, const StringViewLite& strView, const Vector2& dstPositionPxf, const Color& color,
                                   const Vector2& origin, const Vector2& scale, const PxClipRectangle& clipRectPx)
    {
      const auto& fontInfo = font.GetInfo();
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(fontInfo.MaterialInfo.Material.get());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }

      Batch2D::DrawString(Batch2D::texture_type(pNativeTex->Get(), fontInfo.MaterialInfo.ExtentPx), font.GetAtlasBitmapFont(), fontInfo.FontConfig,
                          strView, dstPositionPxf, color, origin, scale, clipRectPx);
    }
    // ----------

    void NativeBatch2D::DebugDrawRectangle(const AtlasTexture2D& srcFillTexture, const PxRectangle& dstRectanglePx, const Color& color)
    {
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(srcFillTexture.TryGetNativePointer());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }

      Batch2D::DebugDrawRectangle(Batch2D::atlas_texture_type(pNativeTex->ToTextureInfo(), srcFillTexture.GetInfo()), dstRectanglePx, color);
    }


    void NativeBatch2D::DebugDrawRectangle(const BaseTexture2D& srcFillTexture, const PxRectangle& dstRectanglePx, const Color& color)
    {
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(srcFillTexture.TryGetNativePointer());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }

      Batch2D::DebugDrawRectangle(pNativeTex->ToTextureInfo(), dstRectanglePx, color);
    }


    void NativeBatch2D::DebugDrawRectangle(const AtlasTexture2D& srcFillTexture, const PxAreaRectangleF& dstRectanglePxf, const Color& color)
    {
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(srcFillTexture.TryGetNativePointer());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }

      Batch2D::DebugDrawRectangle(Batch2D::atlas_texture_type(pNativeTex->ToTextureInfo(), srcFillTexture.GetInfo()), dstRectanglePxf, color);
    }


    void NativeBatch2D::DebugDrawRectangle(const BaseTexture2D& srcFillTexture, const PxAreaRectangleF& dstRectanglePxf, const Color& color)
    {
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(srcFillTexture.TryGetNativePointer());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }

      Batch2D::DebugDrawRectangle(pNativeTex->ToTextureInfo(), dstRectanglePxf, color);
    }

    // ----------

    void NativeBatch2D::DebugDrawLine(const AtlasTexture2D& srcFillTexture, const Vector2& dstFromPxf, const Vector2& dstToPxf, const Color& color)
    {
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(srcFillTexture.TryGetNativePointer());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }

      Batch2D::DebugDrawLine(Batch2D::atlas_texture_type(pNativeTex->ToTextureInfo(), srcFillTexture.GetInfo()), dstFromPxf, dstToPxf, color);
    }


    void NativeBatch2D::DebugDrawLine(const BaseTexture2D& srcFillTexture, const Vector2& dstFromPxf, const Vector2& dstToPxf, const Color& color)
    {
      const auto* pNativeTex = dynamic_cast<const ANativeTexture2D*>(srcFillTexture.TryGetNativePointer());
      if (pNativeTex == nullptr)
      {
        throw std::invalid_argument("srcTexture can not be a invalid texture");
      }

      Batch2D::DebugDrawLine(pNativeTex->ToTextureInfo(), dstFromPxf, dstToPxf, color);
    }
  }
}
