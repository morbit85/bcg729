/*
 computeLP.h

 Copyright (C) 2011 Belledonne Communications, Grenoble, France
 Author : Johan Pascal
 
 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */
#ifndef COMPUTELP_H
#define COMPUTELP_H
/*****************************************************************************/
/* autoCorrelation2LP: convert autocorrelation coefficients to LP using      */
/*                     Levinson-Durbin algo described in spec 3.2.2          */
/*  parameters :                                                             */
/*    -(i) autoCorrelationCoefficients : 11 values in variable scale         */
/*         scale is not needed here as a division cancel it                  */
/*    -(o) LPCoefficientsQ12: 10 LP coefficients in Q12                      */
/*    -(o) reflectionCoefficient: in Q31, k[1] generated during Levinson     */
/*         Durbin LP coefficient generation and needed for VAD               */
/*    -(o) residualEnergy : with the same scale factor as input              */
/*         autoCorrelationCoefficients, needed by DTX                        */
/*                                                                           */
/*****************************************************************************/
void autoCorrelation2LP(word32_t autoCorrelationCoefficients[], word16_t LPCoefficientsQ12[], word32_t *reflectionCoefficient, word32_t *residualEnergy);

/*****************************************************************************/
/* computeLP : As described in spec 3.2.1 and 3.2.2 : Windowing,             */
/*      Autocorrelation and Levinson-Durbin algorithm                        */
/*    parameters:                                                            */
/*      -(i) signal: 240 samples in Q0, the last 40 are from next frame      */
/*      -(o) LPCoefficientsQ12: 10 LP coefficients in Q12                    */
/*      -(o) reflectionCoefficient: in Q31, k[1] generated during Levinson   */
/*           Durbin LP coefficient generation and needed for VAD             */
/*                                                                           */
/*****************************************************************************/
void computeLP(word16_t signal[], word16_t LPCoefficientsQ12[], word32_t *reflectionCoefficient, word32_t autoCorrelationCoefficients[], word32_t noLagAutocorrelationCoefficients[], int8_t *autoCorrelationCoefficientsScale, uint8_t autoCorrelationCoefficientsNumber);
#endif /* ifndef COMPUTELP_H */
