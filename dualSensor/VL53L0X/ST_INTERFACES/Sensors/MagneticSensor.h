/**
 ******************************************************************************
 * @file    MagneticSensor.h
 * @author  AST / EST
 * @version V0.0.1
 * @date    13-April-2015
 * @brief   This file contains the abstract class describing in general
 *          the interfaces of a magnetometer
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; COPYRIGHT(c) 2015 STMicroelectronics</center></h2>
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *   1. Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 *   2. Redistributions in binary form must reproduce the above copyright notice,
 *      this list of conditions and the following disclaimer in the documentation
 *      and/or other materials provided with the distribution.
 *   3. Neither the name of STMicroelectronics nor the names of its contributors
 *      may be used to endorse or promote products derived from this software
 *      without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ******************************************************************************
 */


/* Define to prevent from recursive inclusion --------------------------------*/

#ifndef __MAGNETIC_SENSOR_CLASS_H
#define __MAGNETIC_SENSOR_CLASS_H


/* Includes ------------------------------------------------------------------*/

#include <Component.h>


/* Classes  ------------------------------------------------------------------*/

/**
 * An abstract class for a magnetometer
 */
class MagneticSensor : public Component {
public:

	/**
	 * @brief       Get current magnetometer magnetic X/Y/Z-axes values 
	 *              in standard data units [mgauss]
	 * @param[out]  p_data Pointer to where to store magnetic values to.
	 *              p_data must point to an array of (at least) three elements, where:
	 *              p_data[0] corresponds to X-axis,
	 *              p_data[1] corresponds to Y-axis, and
	 *              p_data[2] corresponds to Z-axis.
	 * @return      0 in case of success, an error code otherwise
	 */
	virtual int get_m_axes(int32_t *p_data) = 0;

	/**
	 * @brief       Get current magnetometer raw data X/Y/Z-axes values 
	 *              in device sepcific LSB units
	 * @param[out]  p_data Pointer to where to store magnetometer raw data to.
	 *              p_data must point to an array of (at least) three elements, where:
	 *              p_data[0] corresponds to X-axis,
	 *              p_data[1] corresponds to Y-axis, and
	 *              p_data[2] corresponds to Z-axis.
	 * @return      0 in case of success, an error code otherwise
	 */
	virtual int get_m_axes_raw(int16_t *p_data) = 0;

    /**
     * @brief Destructor.
     */
	virtual ~MagneticSensor() {};
};

#endif /* __MAGNETIC_SENSOR_CLASS_H */
