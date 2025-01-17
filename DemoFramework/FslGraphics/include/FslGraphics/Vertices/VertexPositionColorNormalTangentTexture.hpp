#ifndef FSLGRAPHICS_VERTICES_VERTEXPOSITIONCOLORNORMALTANGENTTEXTURE_HPP
#define FSLGRAPHICS_VERTICES_VERTEXPOSITIONCOLORNORMALTANGENTTEXTURE_HPP
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

#include <FslBase/Math/Vector2.hpp>
#include <FslBase/Math/Vector3.hpp>
#include <FslBase/Math/Vector4.hpp>
#include <FslGraphics/Vertices/VertexDeclaration.hpp>

namespace Fsl
{
  struct Color;
  class VertexDeclaration;

  struct VertexPositionColorNormalTangentTexture
  {
    Vector3 Position;
    Vector4 Color;
    Vector3 Normal;
    Vector3 Tangent;
    Vector2 TextureCoordinate;

    constexpr VertexPositionColorNormalTangentTexture() noexcept = default;

    constexpr VertexPositionColorNormalTangentTexture(const Vector3& position, const Vector4& color, const Vector3& normal, const Vector3& tangent,
                                                      const Vector2& textureCoordinate) noexcept
      : Position(position)
      , Color(color)
      , Normal(normal)
      , Tangent(tangent)
      , TextureCoordinate(textureCoordinate)
    {
    }

    VertexPositionColorNormalTangentTexture(const Vector3& position, const Fsl::Color& color, const Vector3& normal, const Vector3& tangent,
                                            const Vector2& textureCoordinate);

    //! @brief Get the vertex declaration
    static VertexDeclaration GetVertexDeclaration();
  };
}

#endif
