#ifndef C2A4E2_StorageMap5D_h
#define C2A4E2_StorageMap5D_h

#define StorageMap5D(ptr, idx0, idx1, idx2,idx3, idx4, dim1, dim2, dim3, dim4)(*((ptr)+ (idx0)*(dim1)*(dim2)*(dim3)*(dim4) + (idx1)*(dim2)*(dim3)*(dim4) +\
(idx2)*(dim3)*(dim4) + (idx3)*(dim4) + (idx4)))

#endif 
