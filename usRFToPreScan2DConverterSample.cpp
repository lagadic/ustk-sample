/****************************************************************************
 *
 * This file is part of the UsTk software.
 * Copyright (C) 2014 by Inria. All rights reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License ("GPL") as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 * See the file COPYING at the root directory of this source
 * distribution for additional information about the GNU GPL.
 *
 * This software was developed at:
 * INRIA Rennes - Bretagne Atlantique
 * Campus Universitaire de Beaulieu
 * 35042 Rennes Cedex
 * France
 * http://www.irisa.fr/lagadic
 *
 * If you have questions regarding the use of this file, please contact the
 * authors at Alexandre.Krupa@inria.fr
 *
 * This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 * WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *
 * Authors:
 * Marc Pouliquen
 *
 *****************************************************************************/

#include <visp3/core/vpImage.h>
#include <visp3/ustk_core/usRFToPreScan2DConverter.h>
#include <visp3/ustk_core/usImageRF2D.h>
#include <visp3/ustk_core/usImagePreScan2D.h>

int main()
{
#if defined(USTK_HAVE_FFTW)
  // 2D post-scan image settings
  unsigned int width = 320;
  unsigned int height = 240;
  double transducerRadius = 0.045;
  double scanLinePitch = 0.0012;
  unsigned int scanLineNumber = 256;
  bool isTransducerConvex = true;
  double axialResolution = 0.002;

  vpImage<short int> I(height, width);
  usImageRF2D<short int> rfImage; // to fill (image + settings)
  rfImage.setTransducerRadius(transducerRadius);
  rfImage.setScanLinePitch(scanLinePitch);
  rfImage.setScanLineNumber(scanLineNumber);
  rfImage.setTransducerConvexity(isTransducerConvex);
  rfImage.setAxialResolution(axialResolution);

  usImagePreScan2D<unsigned char> prescanImage; // output
  usRFToPreScan2DConverter converter;
  converter.convert(rfImage,prescanImage);
#endif
  return 0;
}
