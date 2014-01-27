/*
 * Copyright (c) 2012 Aldebaran Robotics. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the COPYING file.
 */
#include <boost/shared_ptr.hpp>

#ifndef _WIN32
# include <signal.h>
#endif

#include <alcommon/albroker.h>
#include <alcommon/albrokermanager.h>
#include <alcommon/altoolsmain.h>

#include "naointerface.h"

#ifdef NAO_IS_REMOTE
# define ALCALL
#else
// When not remote, we are in a dll, so export the entry point
# ifdef _WIN32
#  define ALCALL __declspec(dllexport)
# else
#  define ALCALL
# endif
#endif

extern "C"
{
    ALCALL int _createModule(boost::shared_ptr<AL::ALBroker> broker)
    {
        // Init broker with the main braoker instance
        // from the parent executable
        AL::ALBrokerManager::setInstance(broker->fBrokerManager.lock());
        AL::ALBrokerManager::getInstance()->addBroker(broker);
        // Create module instances
        AL::ALModule::createModule<IAL::NaoInterface>(broker, "IAL::NaoInterface");
        return 0;
    }


    ALCALL int _closeModule()
    {
      return 0;
    }
} // extern "C"

#ifdef NAO_IS_REMOTE
    int main(int argc, char * argv[])
    {
        // Pointer to createModule
        TMainType sig = &_createModule;
        // Call main
        return ALTools::mainFunction("IAL::NaoInterface", argc, argv, sig);
    }
#endif
