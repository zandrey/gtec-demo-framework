#ifndef FSLDEMOHOST_SERVICE_EVENTS_EVENTSSERVICE_HPP
#define FSLDEMOHOST_SERVICE_EVENTS_EVENTSSERVICE_HPP
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

#include <FslDemoApp/Service/ServiceProvider.hpp>
#include <FslDemoApp/Service/Events/IEventService.hpp>
#include <FslDemoHost/Service/ThreadLocal/ThreadLocalService.hpp>
#include <FslDemoHost/Service/Events/IEventPoster.hpp>
#include <list>
#include <queue>

namespace Fsl
{
  class EventsService
    : public ThreadLocalService
    , public IEventService
    , public IEventPoster
  {

    struct EventRecord
    {
      std::shared_ptr<IEvent> ComplexEvent;
      BasicEvent Event;

      EventRecord(const std::shared_ptr<IEvent>& event)
        : ComplexEvent(event)
        , Event()
      {
      }

      EventRecord(const BasicEvent& event)
        : ComplexEvent()
        , Event(event)
      {
      }
    };

    typedef std::weak_ptr<IEventListener> IEventListenerWeakPtr;
    typedef std::list<IEventListenerWeakPtr> EventListenerList;
    typedef std::queue<EventRecord> EventQueue;
    EventListenerList m_listeners;
    EventQueue m_eventQueue1;
    EventQueue m_eventQueue2;
    EventQueue* m_pEventQueue;
    bool m_isLocked;
  public:
    EventsService(const ServiceProvider& serviceProvider);

    virtual void Update() override;

    // From IEventService
    virtual void Register(const std::weak_ptr<IEventListener>& subscriber) override;
    virtual void Unregister(const std::weak_ptr<IEventListener>& subscriber) override;
    // From IEventPoster
    virtual void Post(const std::shared_ptr<IEvent>& event) override;
    virtual void Post(const BasicEvent& event) override;
  private:
    void SendEvent(const EventRecord& eventRecord);
  };
}

#endif
