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

    #include <visp3/ustk_core/usImageRF3D.h>

    int main()
    {
      // Update settings
      unsigned int AN = 200;
      unsigned int LN = 200;
      unsigned int FN = 30;
      double probeRadius = 0.0006;
      double scanLinePitch = 0.0007;
      bool isProbeConvex = true;
      double motorRadius = 0.004;
      double framePitch = 0.06;
      bool isMotorConvex = true;
      double axialResolution = 0.001;
      usImagePreScan3DSettings  imageSettings(probeRadius, scanLinePitch, isProbeConvex, motorRadius, framePitch, isMotorConvex, axialResolution);
      usImage3D<unsigned char> I(AN, LN, FN);
      usImageRF3D<unsigned char> rf3d;
      rf3d.setData(I);
      rf3d.setImageSettings(imageSettings);
    }
