#ifndef FSLDEMOHOST_VULKAN_CONFIG_PHYSICALDEVICECONFIGUTIL_HPP
#define FSLDEMOHOST_VULKAN_CONFIG_PHYSICALDEVICECONFIGUTIL_HPP
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

#include <FslBase/ReadOnlySpan.hpp>
#include <FslDemoHost/Vulkan/Config/DemoAppHostConfigVulkan.hpp>
#include <FslDemoHost/Vulkan/Config/OptionUserChoice.hpp>
#include <deque>
#include <memory>
#include <string>
#include <vector>

namespace Fsl
{
  namespace PhysicalDeviceConfigUtil
  {
    struct DeviceConfig
    {
      std::deque<std::string> Extensions;
    };

    // Transform the config to be accessible as nasty C style arrays
    struct DeviceConfigAsCharArrays
    {
      DeviceConfig Config;
      std::vector<const char*> Extensions;

      explicit DeviceConfigAsCharArrays(const DeviceConfig& config)
        : Config(config)
        , Extensions(config.Extensions.size())
      {
        for (std::size_t i = 0; i < Config.Extensions.size(); ++i)
        {
          Extensions[i] = Config.Extensions[i].c_str();
        }
      }
    };


    //! @brief
    //! @param device
    //! @param customdemoAppHostConfig a optional demo app host config
    DeviceConfig BuildConfig(const VkPhysicalDevice device, const std::shared_ptr<DemoAppHostConfigVulkan>& customDemoAppHostConfig,
                             const ReadOnlySpan<Vulkan::FeatureRequest> hostExtensionRequests);
  }
}

#endif
