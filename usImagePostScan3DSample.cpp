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



#include <visp3/ustk_core/usImagePostScan3D.h>

int main()
{
  // Transducer settings
  unsigned int BModeSampleNumber = 200;
  double transducerRadius = 0.045;;
  double scanLinePitch = 0.01;
  unsigned int scanLineNumber = 256;
  bool isTransducerConvex = true;
  double axialResolution = 0.001;

  // Motor settings
  double motorRadius = 0.004;
  double framePitch = 0.06;
  unsigned int frameNumber = 10;
  usMotorSettings::usMotorType motorType = usMotorSettings::LinearMotor;

  // Post-scan data settings
  unsigned int dimX = 200;
  unsigned int dimY = 200;
  unsigned int dimZ = 20;

  usTransducerSettings transducerSettings;
  transducerSettings.setTransducerRadius(transducerRadius);
  transducerSettings.setScanLinePitch(scanLinePitch);
  transducerSettings.setScanLineNumber(scanLineNumber);
  transducerSettings.setTransducerConvexity(isTransducerConvex);

  usMotorSettings motorSettings;
  motorSettings.setMotorRadius(motorRadius);
  motorSettings.setFramePitch(framePitch);
  motorSettings.setFrameNumber(frameNumber);
  motorSettings.setMotorType(motorType);

  usImage3D<unsigned char> I(dimX, dimY, dimZ);

  usImagePostScan3D<unsigned char> postScan3d;
  postScan3d.setData(I);
  postScan3d.setTransducerSettings(transducerSettings);
  postScan3d.setMotorSettings(motorSettings);
}
