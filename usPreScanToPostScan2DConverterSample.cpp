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

#include <visp3/ustk_core/usPreScanToPostScan2DConverter.h>

int main()
{
  // 2D pre-scan image settings
  unsigned int width = 320;
  unsigned int height = 240;
  double transducerRadius = 0.045;
  double scanLinePitch = 0.0012;
  unsigned int scanLineNumber = 256;
  bool isTransducerConvex = true;
  double axialResolution = 0.002;

  vpImage<unsigned char> I(height, width);
  usImagePreScan2D <unsigned char> preScan; // your input pre-scan image
  // then you have can fill the preScan image and settings
  preScan.setTransducerRadius(transducerRadius);
  preScan.setScanLinePitch(scanLinePitch);
  preScan.setScanLineNumber(scanLineNumber);
  preScan.setTransducerConvexity(isTransducerConvex);
  preScan.setAxialResolution(axialResolution);
  preScan.setData(I);

  // converter output
  usImagePostScan2D<unsigned char> postScan;
  usPreScanToPostScan2DConverter scanConverter;
  scanConverter.convert(preScan,postScan,0.0005,0.0005); // now postScan is filled from preScan, with pixels of 0.5mm

  return 0;
}
