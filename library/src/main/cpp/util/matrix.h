/*
 * Copyright (C) 2020 Mobisoft. All rights reserved.
 * Copyright (C) 2020 Shubham Kamlapuri <shubhwicked@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

//
// Created by Shubham on 2020/4/2.
//

#ifndef MOBISOFT_MATRIX_H
#define MOBISOFT_MATRIX_H

#include <math.h>
#include <stdlib.h>
#include <string>

void matrixSetIdentityM(float *m);
void matrixSetRotateM(float *m, float a, float x, float y, float z);
void matrixMultiplyMM(float *m, float *lhs, float *rhs);
void matrixScaleM(float *m, float x, float y, float z);
void matrixTranslateM(float *m, float x, float y, float z);
void matrixRotateM(float *m, float a, float x, float y, float z);
void matrixLookAtM(float *m, float eyeX, float eyeY, float eyeZ, float cenX,
			float cenY, float cenZ, float upX, float upY, float upZ);
void matrixFrustumM(float *m, float left, float right, float bottom, float top, float near, float far);

void getTranslateMatrix(float *m, float x, float y, float z);

#endif  // MOBISOFT_MATRIX_H
