/*
==================================================================================================================================================================================
Name : 2.c
Shubhi kesarwani


Sample Output:
System Resource Limits:
CPU Time Limit: Soft Limit = 18446744073709551615, Hard Limit = 18446744073709551615
Maximum File Size: Soft Limit = 18446744073709551615, Hard Limit = 18446744073709551615
Maximum Data Size: Soft Limit = 18446744073709551615, Hard Limit = 18446744073709551615
Maximum Stack Size: Soft Limit = 8388608, Hard Limit = 18446744073709551615
Maximum Core File Size: Soft Limit = 0, Hard Limit = 18446744073709551615
Maximum Resident Set Size: Soft Limit = 18446744073709551615, Hard Limit = 18446744073709551615
Maximum Number of Processes: Soft Limit = 30500, Hard Limit = 30500
Maximum Number of Open Files: Soft Limit = 1024, Hard Limit = 1048576
Maximum Locked-in-Memory Address Space: Soft Limit = 1009016832, Hard Limit = 1009016832
Maximum Virtual Memory Size: Soft Limit = 18446744073709551615, Hard Limit = 18446744073709551615
Maximum Number of File Locks: Soft Limit = 18446744073709551615, Hard Limit = 18446744073709551615
Maximum Number of Pending Signals: Soft Limit = 30500, Hard Limit = 30500
Maximum Bytes in POSIX Message Queues: Soft Limit = 819200, Hard Limit = 819200
Maximum Nice Priority: Soft Limit = 0, Hard Limit = 0
Maximum Realtime Priority: Soft Limit = 0, Hard Limit = 0
Maximum Realtime CPU Time: Soft Limit = 18446744073709551615, Hard Limit = 18446744073709551615


==================================================================================================================================================================================
*/
#include <stdio.h>
#include <sys/resource.h>

void print_resource_limits() {
    struct rlimit limit;

    // Array of resource types to check
    int r[] = {
        RLIMIT_CPU,         
        RLIMIT_FSIZE,       
        RLIMIT_DATA,        
        RLIMIT_STACK,      
        RLIMIT_CORE,        
        RLIMIT_RSS,         
        RLIMIT_NPROC,       
        RLIMIT_NOFILE,      
        RLIMIT_MEMLOCK,    
        RLIMIT_AS,          
        RLIMIT_LOCKS,       
        RLIMIT_SIGPENDING,   
        RLIMIT_MSGQUEUE,    
        RLIMIT_NICE,        
        RLIMIT_RTPRIO,     
        RLIMIT_RTTIME       
    };

    const char *resource_names[] = {
        "CPU Time Limit",
        "Maximum File Size",
        "Maximum Data Size",
        "Maximum Stack Size",
        "Maximum Core File Size",
        "Maximum Resident Set Size",
        "Maximum Number of Processes",
        "Maximum Number of Open Files",
        "Maximum Locked-in-Memory Address Space",
        "Maximum Virtual Memory Size",
        "Maximum Number of File Locks",
        "Maximum Number of Pending Signals",
        "Maximum Bytes in POSIX Message Queues",
        "Maximum Nice Priority",
        "Maximum Realtime Priority",
        "Maximum Realtime CPU Time"
    };

    printf("System Resource Limits:\n");
    for (int i = 0; i < sizeof(r)/sizeof(r[0]); i++) {
        if (getrlimit(r[i], &limit) == 0) {
            printf("%s: Soft Limit = %lu, Hard Limit = %lu\n",
                   resource_names[i], limit.rlim_cur, limit.rlim_max);
        } else {
            perror("getrlimit");
        }
    }
}

int main() {
    print_resource_limits();
    return 0;
}
