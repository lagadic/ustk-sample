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

#include <visp3/ustk_core/usPreScanToPostScan3DConverter.h>

int main()
{
  // 3D pre-scan image settings
  unsigned int width = 320;
  unsigned int height = 240;
  unsigned int frames = 10;
  double transducerRadius = 0.045;
  double scanLinePitch = 0.0012;
  unsigned int scanLineNumber = 256;
  bool isTransducerConvex = true;
  double axialResolution = 0.002;
  double framePitch = 0.002;
  double motorRadius = 0.04;

  usImage3D<unsigned char> I(height, width, frames);
  usImagePreScan3D <unsigned char> preScan; // your input pre-scan image
  // then you have can fill the preScan image and settings
  preScan.setTransducerRadius(transducerRadius);
  preScan.setScanLinePitch(scanLinePitch);
  preScan.setScanLineNumber(scanLineNumber);
  preScan.setTransducerConvexity(isTransducerConvex);
  preScan.setAxialResolution(axialResolution);
  preScan.setMotorRadius(motorRadius);
  preScan.setMotorType(usMotorSettings::TiltingMotor);
  preScan.setFramePitch(framePitch);

  preScan.setData(I);

  usImagePostScan3D<unsigned char> postscanImage;
  //scan-converster
  usPreScanToPostScan3DConverter converter;
  converter.init(preScan);
  converter.convert(postscanImage, preScan);
  return 0;
}
