#ifndef FSLDEMOHOST_SERVICE_THREADLOCAL_THREADLOCALSINGLETONSERVICEFACTORYTEMPLATE_HPP
#define FSLDEMOHOST_SERVICE_THREADLOCAL_THREADLOCALSINGLETONSERVICEFACTORYTEMPLATE_HPP
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

#include <FslDemoHost/Service/ThreadLocal/ThreadLocalSingletonServiceFactoryBase.hpp>

namespace Fsl
{
  template<typename T>
  class ThreadLocalSingletonServiceFactoryTemplate0 : public ThreadLocalSingletonServiceFactoryBase
  {
  public:
    ThreadLocalSingletonServiceFactoryTemplate0()
      : ThreadLocalSingletonServiceFactoryBase(TypeInfo(typeid(T)))
    {
    }

    ThreadLocalSingletonServiceFactoryTemplate0(const ServiceCaps::Flags flags)
      : ThreadLocalSingletonServiceFactoryBase(TypeInfo(typeid(T)), flags)
    {
    }

    virtual std::shared_ptr<IService> Allocate(ServiceProvider& provider) override
    {
      return std::shared_ptr<IService>(new T(provider));
    }
  };


  template<typename T, typename TItf>
  class ThreadLocalSingletonServiceFactoryTemplate : public ThreadLocalSingletonServiceFactoryBase
  {
  public:
    ThreadLocalSingletonServiceFactoryTemplate()
      : ThreadLocalSingletonServiceFactoryBase(TypeInfo(typeid(TItf)))
    {
    }

    ThreadLocalSingletonServiceFactoryTemplate(const ServiceCaps::Flags flags)
      : ThreadLocalSingletonServiceFactoryBase(TypeInfo(typeid(TItf)), flags)
    {
    }

    virtual std::shared_ptr<IService> Allocate(ServiceProvider& provider) override
    {
      return std::shared_ptr<IService>(new T(provider));
    }
  };


  template<typename T, typename TItf1, typename TItf2>
  class ThreadLocalSingletonServiceFactoryTemplate2 : public IThreadLocalSingletonServiceFactory
  {
    ServiceCaps::Flags m_flags;
  public:
    ThreadLocalSingletonServiceFactoryTemplate2()
      : m_flags(ServiceCaps::Default)
    {
    }

    ThreadLocalSingletonServiceFactoryTemplate2(const ServiceCaps::Flags flags)
      : m_flags(flags)
    {
    }


    virtual std::shared_ptr<AServiceOptionParser> GetOptionParser() const override
    {
      return std::shared_ptr<AServiceOptionParser>();
    }


    virtual ServiceCaps::Flags GetFlags() const override
    {
      return m_flags;
    }

    virtual void FillInterfaceType(ServiceSupportedInterfaceDeque& rServiceInterfaceTypeDeque) const override
    {
      rServiceInterfaceTypeDeque.push_back(TypeInfo(typeid(TItf1)));
      rServiceInterfaceTypeDeque.push_back(TypeInfo(typeid(TItf2)));
    }


    virtual std::shared_ptr<IService> Allocate(ServiceProvider& provider) override
    {
      return std::shared_ptr<IService>(new T(provider));
    }
  };


  template<typename T, typename TItf1, typename TItf2, typename TItf3>
  class ThreadLocalSingletonServiceFactoryTemplate3 : public IThreadLocalSingletonServiceFactory
  {
    ServiceCaps::Flags m_flags;
  public:
    ThreadLocalSingletonServiceFactoryTemplate3()
      : m_flags(ServiceCaps::Default)
    {
    }

    ThreadLocalSingletonServiceFactoryTemplate3(const ServiceCaps::Flags flags)
      : m_flags(flags)
    {
    }

    virtual ServiceCaps::Flags GetFlags() const override
    {
      return m_flags;
    }

    virtual void FillInterfaceType(ServiceSupportedInterfaceDeque& rServiceInterfaceTypeDeque) const override
    {
      rServiceInterfaceTypeDeque.push_back(TypeInfo(typeid(TItf1)));
      rServiceInterfaceTypeDeque.push_back(TypeInfo(typeid(TItf2)));
      rServiceInterfaceTypeDeque.push_back(TypeInfo(typeid(TItf3)));
    }


    virtual std::shared_ptr<IService> Allocate(ServiceProvider& provider) override
    {
      return std::shared_ptr<IService>(new T(provider));
    }
  };
}

#endif
