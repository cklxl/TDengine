/*
 * Copyright (c) 2019 TAOS Data, Inc. <jhtao@taosdata.com>
 *
 * This program is free software: you can use, redistribute, and/or modify
 * it under the terms of the GNU Affero General Public License, version 3
 * or later ("AGPL"), as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TDENGINE_TAOSARRAY_H
#define TDENGINE_TAOSARRAY_H

#ifdef __cplusplus
extern "C" {
#endif

#include "os.h"

#define TARRAY_MIN_SIZE 8
#define TARRAY_GET_ELEM(array, index) ((array)->pData + (index) * (array)->elemSize)

typedef struct SArray {
  size_t size;
  size_t capacity;
  size_t elemSize;

  void* pData;
} SArray;

/**
 *
 * @param size
 * @param elemSize
 * @return
 */
void* taosArrayInit(size_t size, size_t elemSize);

/**
 *
 * @param pArray
 * @param pData
 * @return
 */
void* taosArrayPush(SArray* pArray, void* pData);

/**
 *
 * @param pArray
 */
void* taosArrayPop(SArray* pArray);

/**
 * get the data from array
 * @param pArray
 * @param index
 * @return
 */
void* taosArrayGet(SArray* pArray, size_t index);

/**
 * get the pointer data from the array
 * @param pArray
 * @param index
 * @return
 */
void* taosArrayGetP(SArray* pArray, size_t index);

/**
 * return the size of array
 * @param pArray
 * @return
 */
size_t taosArrayGetSize(const SArray* pArray);

/**
 * insert data into array
 * @param pArray
 * @param index
 * @param pData
 */
void* taosArrayInsert(SArray* pArray, size_t index, void* pData);

/**
 * remove data entry of the given index
 * @param pArray
 * @param index
 */
void taosArrayRemove(SArray* pArray, size_t index);

/**
 * copy the whole array from source to destination
 * @param pDst
 * @param pSrc
 */
void taosArrayCopy(SArray* pDst, SArray* pSrc);

/**
 * clone a new array
 * @param pSrc
 */
SArray* taosArrayClone(SArray* pSrc);

/**
 * destroy array list
 * @param pArray
 */
void taosArrayDestroy(SArray* pArray);

/**
 * sort the array
 * @param pArray
 * @param compar
 */
void taosArraySort(SArray* pArray, int (*compar)(const void*, const void*));

/**
 * search the array
 * @param pArray
 * @param compar
 * @param key
 */
void* taosArraySearch(SArray* pArray, int (*compar)(const void*, const void*), const void* key);

#ifdef __cplusplus
}
#endif

#endif  // TDENGINE_TAOSARRAY_H
