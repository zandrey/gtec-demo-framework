#ifndef FSLGRAPHICS_VERTICES_VERTEXPOSITIONTEXTURETEXTURE_HPP
#define FSLGRAPHICS_VERTICES_VERTEXPOSITIONTEXTURETEXTURE_HPP
/****************************************************************************************************************************************************
 * Copyright 2019 NXP
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

#include <FslBase/Math/Vector2.hpp>
#include <FslBase/Math/Vector3.hpp>
#include <FslGraphics/Vertices/VertexDeclaration.hpp>

namespace Fsl
{
  class VertexDeclaration;

  struct VertexPositionTextureTexture
  {
    Vector3 Position;
    Vector2 TextureCoordinate0;
    Vector2 TextureCoordinate1;

    constexpr VertexPositionTextureTexture() noexcept = default;

    constexpr VertexPositionTextureTexture(const Vector3& position, const Vector2& texture0, const Vector2& texture1) noexcept
      : Position(position)
      , TextureCoordinate0(texture0)
      , TextureCoordinate1(texture1)
    {
    }

    //! @brief Get the vertex declaration
    static VertexDeclaration GetVertexDeclaration();
  };
}

#endif
