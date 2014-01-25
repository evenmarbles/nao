#include "worldobjectmanager.h"

#include <cstdlib>
#include <cassert>

#include "ball.h"

using namespace IAL;

WorldObjectManager * WorldObjectManager::sInstance = NULL;


WorldObjectManager::WorldObjectManager()
{
    assert(sInstance == NULL);
    sInstance = static_cast<WorldObjectManager *>(this);

    init();
}

WorldObjectManager::~WorldObjectManager()
{
    sInstance = NULL;
}


WorldObjectManager & WorldObjectManager::getInstance()
{
    if (sInstance == NULL)
    {
        sInstance = createInstance();
        scheduleForDestruction(destroy);
    }
    return *sInstance;
}

void WorldObjectManager::destroy()
{
    if (sInstance != NULL)
    {
        destroyInstance(sInstance);
        sInstance = NULL;
    }
}

WorldObjectManager * WorldObjectManager::createInstance()
{
    return new WorldObjectManager();
}

void WorldObjectManager::scheduleForDestruction(void (*fkt)())
{
    std::atexit(fkt);
}

void WorldObjectManager::destroyInstance(WorldObjectManager * manager)
{
    delete manager;
}


void WorldObjectManager::init()
{
    boost::shared_ptr<Ball> ball(new Ball);
    mWorldObjects.push_back(ball);
}
