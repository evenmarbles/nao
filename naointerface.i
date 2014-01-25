%module naointerface
%include <boost_shared_ptr.i>
%shared_ptr(IAL::WorldObject)
%shared_ptr(IAL::Ball)

%{
#define SWIG_FILE_WITH_INIT
#include "core/common/worldobject.h"
#include "core/common/ball.h"
#include "core/common/worldobjectmanager.h"
%}

%include "core/common/worldobject.h"
%include "core/common/ball.h"
%include "core/common/worldobjectmanager.h"

%inline %{
    using namespace IAL;
    Ball_ptr getGameBall()
    {
        Ball_ptr gameBall = boost::static_pointer_cast<Ball>(WorldObjectManager::getInstance().getWorldObject(WORLD_OBJECT_BALL));
        return gameBall;
    }

%}
