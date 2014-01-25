#ifndef WORLDOBJECTMANAGER_H
#define WORLDOBJECTMANAGER_H

#include <vector>

#include "enums.h"
#include "worldobject.h"


namespace IAL
{
    class WorldObjectManager
    {
    public:
        ~WorldObjectManager();

        WorldObject_ptr getWorldObject(WorldObjectType type)  { return mWorldObjects[type]; }

        static WorldObjectManager & getInstance();
        static void destroy();

    private:
        WorldObjectManager();

        WorldObjectManager(WorldObjectManager const &) {}
        WorldObjectManager & operator=(WorldObjectManager const &)  { return *this; }

        void init();

        static WorldObjectManager * createInstance();
        static void scheduleForDestruction(void (*)());
        static void destroyInstance(WorldObjectManager *);

        static WorldObjectManager * sInstance;

        std::vector<WorldObject_ptr> mWorldObjects;
    };
}

#endif // WORLDOBJECTMANAGER_H
