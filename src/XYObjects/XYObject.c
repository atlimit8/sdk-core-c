/**
 ****************************************************************************************
 *
 * @file xyobject.c
 *
 * @XYO Core library source code.
 *
 * @brief primary xy object routines for the XYO Core.
 *
 * Copyright (C) 2018 XY - The Findables Company
 *
 ****************************************************************************************
 */

/*
 * INCLUDES
 ****************************************************************************************
 */

#include "XYObject.h"
#include "XYObjectHeader.h"

/**
 * ==== Private Functions ====
 */

//assuming validation by caller
int getLength(XYObject_t* self) {
  XYHeader_t header;
  XYOBJ_COPY_UINT8_ARRAY(&header, XY_HEADER_OFFSET, XY_HEADER_LENGTH);

  switch(header.flags.lengthType) {
    case XY_LENGTH_1BYTE:
      return XYOBJ_READ_UINT8(XY_LENGTH_OFFSET);
    case XY_LENGTH_2BYTE:
      return XYOBJ_READ_UINT16(XY_LENGTH_OFFSET);
    case XY_LENGTH_4BYTE:
      return XYOBJ_READ_UINT32(XY_LENGTH_OFFSET);
    case XY_LENGTH_8BYTE:
      return XYOBJ_READ_UINT64(XY_LENGTH_OFFSET);
  }

  return 0;
}

//assuming validation by caller
int getLengthFieldSize(XYObject_t* self) {
  XYHeader_t header;
  XYOBJ_COPY_UINT8_ARRAY(&header, XY_HEADER_OFFSET, XY_HEADER_LENGTH);

  switch(header.flags.lengthType) {
    case XY_LENGTH_1BYTE:
      return 1;
    case XY_LENGTH_2BYTE:
      return 2;
    case XY_LENGTH_4BYTE:
      return 4;
    case XY_LENGTH_8BYTE:
      return 8;
  }

  return 0;
}

/**
 * ==== Public Functions ====
 */

XYResult_t XYObject_getHeader(XYObject_t* self) {
  INIT_SELF_UNKNOWN();
  XYOBJ_COPY_UINT8_ARRAY(result.value.bytes, XY_HEADER_OFFSET, XY_HEADER_LENGTH);
  return result;
}

XYResult_t XYObject_getValue(XYObject_t* self) {
  INIT_SELF_UNKNOWN();
  result.value.ptr = ((uint8_t*)self) + getLengthFieldSize(self);
  return result;
}

XYResult_t XYObject_getLength(XYObject_t* self) {
  INIT_SELF_UNKNOWN();
  result.value.i = getLength(self);
  return result;
}

XYResult_t XYObject_getFullLength(XYObject_t* self) {
  INIT_SELF_UNKNOWN();
  result.value.i = getLength(self) + XY_HEADER_LENGTH;
  return result;
}