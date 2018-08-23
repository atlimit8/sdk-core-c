/**
 * @Author: Nate Brune
 * @Date:   10-Aug-2018
 * @Email:  nate.brune@xyo.network
 * @Project: XYO-C-SDK
 * @Filename: main.c
 * @Last modified by:   Nate Brune
 * @Last modified time: 10-Aug-2018
 * @Copyright: XY - The Findables Company
 */
#include "xyo.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <openssl/sha.h>

int init(){
  preallocated_result = malloc(XYResult);
  if(preallocated_result){
    initTable();
  }
  else{
    return -1;
  }
  return 0;
}
