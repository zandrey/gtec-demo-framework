#ifndef FSLGRAPHICS_BITMAP_BITMAP_HPP
#define FSLGRAPHICS_BITMAP_BITMAP_HPP
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

#include <FslBase/Math/Point2.hpp>
#include <FslGraphics/Bitmap/BitmapOrigin.hpp>
#include <FslGraphics/Bitmap/RawBitmap.hpp>
#include <FslGraphics/Bitmap/RawBitmapEx.hpp>
#include <FslGraphics/Bitmap/BitmapClearMethod.hpp>
#include <FslGraphics/StrideRequirement.hpp>

#include <vector>

namespace Fsl
{

  //@note All the methods that will default to using StrideRequirement::Any will use the minimum stride for allocation of the bitmap.
  //      The none part is just set to mean that there are no special requirements that should be maintained for the bitmap if its
  //      modified.
  class Bitmap
  {
    //! The raw image data
    std::vector<uint32_t> m_content;
    Extent2D m_extent;
    uint32_t m_stride;
    PixelFormat m_pixelFormat;
    StrideRequirement m_strideRequirement;
    BitmapOrigin m_origin;
    mutable bool m_isLocked;
  public:
    // move assignment operator
    Bitmap& operator=(Bitmap&& other);
    // move constructor
    Bitmap(Bitmap&& other);
    // Request that the compiler generates a copy constructor and assignment operator
    Bitmap(const Bitmap&) = default;
    Bitmap& operator= (const Bitmap&) = default;

    //! @brief Create a empty bitmap
    Bitmap();

    //! @brief Create a empty bitmap of the given width, height and pixel format (The default stride preference is StrideRequirement::Any)
    Bitmap(const Extent2D& extent, const PixelFormat pixelFormat, const BitmapOrigin bitmapOrigin = BitmapOrigin::UpperLeft);

    //! @brief Create a empty bitmap of the given width, height, pixel format and stride (The default stride preference is StrideRequirement::Any)
    Bitmap(const Extent2D& extent, const PixelFormat pixelFormat, const uint32_t stride, const BitmapOrigin bitmapOrigin = BitmapOrigin::UpperLeft);

    //! @brief Create a bitmap from the supplied content (the content will be copied).
    //         The input bitmap is assumed to use the minimum stride and the created bitmap will use StrideRequirement::Any to find its stride.
    Bitmap(const void*const pContent, const Extent2D& extent, const PixelFormat pixelFormat, const BitmapOrigin bitmapOrigin = BitmapOrigin::UpperLeft);

    //! @brief Create a bitmap from the supplied content (the content will be copied).
    //         The created bitmap will use StrideRequirement::Any to find its stride.
    Bitmap(const void*const pContent, const Extent2D& extent, const PixelFormat pixelFormat, const uint32_t stride, const BitmapOrigin bitmapOrigin = BitmapOrigin::UpperLeft);

    //! @brief Create a bitmap from the supplied content (the content will be copied).
    //         The created bitmap will use StrideRequirement::Any to find its stride.
    Bitmap(const RawBitmap& srcBitmap);

    //! @brief Create a bitmap from the supplied content (the content will be copied).
    //         The created bitmap will use StrideRequirement::Any to find its stride.
    //! @param desiredOrigin the origin that the created bitmap should use (if the src bitmap differs it is converted)
    Bitmap(const RawBitmap& srcBitmap, const BitmapOrigin desiredOrigin);


    //! Just some ease of use overloads
    Bitmap(const int32_t width, const int32_t height, const PixelFormat pixelFormat, const BitmapOrigin bitmapOrigin = BitmapOrigin::UpperLeft)
      : Bitmap(Extent2D(width, height), pixelFormat, bitmapOrigin)
    {
    }

    ~Bitmap();

    bool IsValid() const
    {
      return m_content.data() != nullptr;
    }

    //! @brief The width of the bitmap in pixels
    uint32_t Width() const;

    //! @brief The height of the bitmap in pixels
    uint32_t Height() const;

    //! @brief The size of the bitmap in pixels
    Point2 Size() const;

    //! @brief The stride of the bitmap in bytes
    uint32_t Stride() const;

    //! @brief The size of the bitmap in pixels
    Extent2D GetExtent() const;

    //! @brief Get the origin of the bitmap
    BitmapOrigin GetOrigin() const;

    //! @brief Get the bitmap stride preference.
    StrideRequirement GetStrideRequirement() const;

    //! @brief Get the pixel format of the raw bitmap
    PixelFormat GetPixelFormat() const;

    //! @brief Get the pixel format layout of the raw bitmap
    PixelFormatLayout GetPixelFormatLayout() const;

    //! @brief Get the stride that this bitmap would prefer given it had to be stored in the given pixel format.
    //! @note  This takes into account the current StrideRequirement of the bitmap.
    uint32_t GetPreferredStride(const PixelFormat pixelFormat) const;

    void Reset();


    //! @brief Reset the image to the given dimensions.
    //! @param clearMethod defines what to do with the existing content
    //! @note This resets the stride preference to StrideRequirement::Any
    void Reset(const Extent2D& extent, const PixelFormat pixelFormat, const BitmapOrigin origin = BitmapOrigin::UpperLeft, const BitmapClearMethod clearMethod = BitmapClearMethod::Clear);

    //! @brief Reset the image to the given dimensions.
    //! @param clearMethod defines what to do with the existing content
    //! @note This resets the stride preference to StrideRequirement::Any
    void Reset(const Extent2D& extent, const PixelFormat pixelFormat, const uint32_t stride, const BitmapOrigin origin = BitmapOrigin::UpperLeft, const BitmapClearMethod clearMethod = BitmapClearMethod::Clear);

    //! @brief Create a bitmap from the supplied content (the content will be copied).
    //         The input bitmap is assumed to use the minimum stride and the created bitmap will use StrideRequirement::Any to find its stride.
    //! @note This resets the stride preference to StrideRequirement::Any
    void Reset(const void*const pContent, const Extent2D& extent, const PixelFormat pixelFormat, const BitmapOrigin origin = BitmapOrigin::UpperLeft);

    //! @brief Create a bitmap from the supplied content (the content will be copied).
    //         The created bitmap will use StrideRequirement::Any to find its stride.
    //! @note This resets the stride preference to StrideRequirement::Any
    void Reset(const void*const pContent, const Extent2D& extent, const PixelFormat pixelFormat, const uint32_t stride, const BitmapOrigin origin = BitmapOrigin::UpperLeft);

    //! @brief Create a bitmap from the supplied content (the content will be copied).
    //         The created bitmap will use StrideRequirement::Any to find its stride.
    //! @note This resets the stride preference to StrideRequirement::Any
    void Reset(const RawBitmap& srcBitmap);


    void Reset(const int32_t width, const int32_t height, const PixelFormat pixelFormat, const BitmapOrigin bitmapOrigin = BitmapOrigin::UpperLeft, const BitmapClearMethod clearMethod = BitmapClearMethod::Clear)
    {
      Reset(Extent2D(width, height), pixelFormat, bitmapOrigin, clearMethod);
    }

    void Reset(const int32_t width, const int32_t height, const PixelFormat pixelFormat, const uint32_t stride, const BitmapOrigin bitmapOrigin = BitmapOrigin::UpperLeft, const BitmapClearMethod clearMethod = BitmapClearMethod::Clear)
    {
      Reset(Extent2D(width, height), pixelFormat, stride, bitmapOrigin, clearMethod);
    }


    //! @brief set the pixel at the given coordinate (if the coordinate is outside the bitmap nothing happens)
    //! @note SetNativePixel always treats 0,0 as the upper left corner regardless of the origin
    //! @note This is a very slow operation
    void SetNativePixel(const int32_t x, const int32_t y, const uint32_t color);

    //! @brief set the pixel at the given coordinate (if the coordinate is outside the bitmap nothing happens)
    //! @note SetNativePixel always treats 0,0 as the upper left corner regardless of the origin
    //! @note This is a very slow operation
    void SetNativePixel(const uint32_t x, const uint32_t y, const uint32_t color);

    //! @brief read the pixel at the given coordinate (if the coordinate is outside the bitmap zero is returned)
    //! @note GetNativePixel always treats 0,0 as the upper left corner regardless of the origin
    //! @note This is a very slow operation
    uint32_t GetNativePixel(const int32_t x, const int32_t y) const;

    //! @brief read the pixel at the given coordinate (if the coordinate is outside the bitmap zero is returned)
    //! @note GetNativePixel always treats 0,0 as the upper left corner regardless of the origin
    //! @note This is a very slow operation
    uint32_t GetNativePixel(const uint32_t x, const uint32_t y) const;

    //! @brief Allows the bitmap pixel format to be modified as long as the pixel formats memory layout is compatible
    //! @note This only changes the 'PixelFormat' type it does not modify any bitmap pixels. So if you call this beware of this!
    void SetCompatiblePixelFormat(const PixelFormat compatiblePixelFormat);

    //! Provides direct access to the scoped bitmap during its lifetime.
    class ScopedDirectAccess
    {
      const Bitmap* m_pBitmap1;
      Bitmap* m_pBitmap2;
      RawBitmapEx* m_pRawBitmapEx;
    public:
      ScopedDirectAccess(const ScopedDirectAccess&) = delete;
      ScopedDirectAccess& operator=(const ScopedDirectAccess&) = delete;

      // Read only lock
      ScopedDirectAccess(const Bitmap& bitmap, RawBitmap& rRawBitmap)
        : m_pBitmap1(&bitmap)
        , m_pBitmap2(nullptr)
        , m_pRawBitmapEx(nullptr)
      {
        rRawBitmap = bitmap.Lock();
      }

      // Read/write lock
      ScopedDirectAccess(Bitmap& bitmap, RawBitmapEx& rRawBitmap)
        : m_pBitmap1(nullptr)
        , m_pBitmap2(&bitmap)
        , m_pRawBitmapEx(&rRawBitmap)
      {
        rRawBitmap = bitmap.LockEx();
      }

      ~ScopedDirectAccess()
      {
        if (m_pBitmap1 != nullptr)
          m_pBitmap1->Unlock();
        else if (m_pBitmap2 != nullptr)
        {
          m_pBitmap2->UnlockEx(*m_pRawBitmapEx);
        }
      }
    };
  private:
    RawBitmap Lock() const;
    RawBitmapEx LockEx();
    void UnlockEx(const RawBitmapEx& bitmap);
    void Unlock() const;
    void ResizeToFit(const Extent2D& extent, const PixelFormat pixelFormat, const StrideRequirement strideRequirement, const uint32_t stride = 0);
    void Clear(const BitmapClearMethod clearMethod);
    void ResetNoThrow();
  };
}

#endif
