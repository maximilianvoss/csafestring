#Library csafestring

This is a small library to handle safely string operations in C. It is a wrapper around the standard string.h functionalities.

__How it works:__  
A object called safestring_t is going to created. It contains the actual data and information of how many bytes are 
allocated to this datastore. If the all methods are 1:1 equivalent to the methods from string.h, despite they accept
only safestring_t objects.  
Whenever there is a function call having possible impact to the array's size it will be checked and increased if needed 
before data is stored.

__Auto Memory Increasement:__  
While initializing the datastores size is set to INIT_LENGTH (default: 4 bytes).  
If the new data does not fit, it will be increased always by the power of 2, until the new data fits into the array. This
method is used that multiple string concatinations for example won't cause multiple reallocations.  