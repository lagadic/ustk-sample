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
    #include <visp3/ustk_core/usImagePostScan2D.h>

    int main()
    {
      // Update settings
      unsigned int dimX = 200;
      unsigned int dimY = 200;
      double probeRadius = 0.045;
      double scanLinePitch = 0.0012;
      bool isTransducerConvex = true;
      double heightResolution = 0.002;
      double widthResolution = 0.004;
      usImagePostScanSettings imageSettings(probeRadius, scanLinePitch, isTransducerConvex, heightResolution, widthResolution);
      vpImage<unsigned char> I(dimY,dimX);
      usImagePostScan2D<unsigned char> postScan2d;
      postScan2d.setData(I);
      postScan2d.setImageSettings(imageSettings);
    }
