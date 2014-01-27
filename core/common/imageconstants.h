#ifndef IMAGECONSTANTS_H
#define IMAGECONSTANTS_H

#include "../math/mathdefs.h"

#ifdef SIM
# define IMAGE_WIDTH 320
# define IMAGE_HEIGHT 240

# define HFOV 1.064
# define VFOV HFOV*IMAGE_HEIGHT/IMAGE_WIDTH    //0.798
#else
# define IMAGE_WIDTH 640
# define IMAGE_HEIGHT 480

#if defined(NAO4_0)
# define HFOV kDegToRad * 60.9
# define VFOV kDegToRad * 47.6
#elif defined(NAO3_2) || defined(NAO3_3)
# define HFOV kDegToRad * 47.8
# define VFOV kDegToRad * 36.8
#endif // endif NAO3_3 || NAO3_2
#endif // endif SIM

#endif // IMAGECONSTANTS_H
