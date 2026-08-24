//Aneri Raval q2
#include <stdio.h>
#include <math.h>

int main() {
    long long process_size, logical_addr_bits, main_mem_size, page_size;

    printf("Enter Process Size (bytes): ");
    scanf("%lld", &process_size);

    printf("Enter Logical Address (bits): ");
    scanf("%lld", &logical_addr_bits);

    printf("Enter Main Memory Size (bytes): ");
    scanf("%lld", &main_mem_size);

    printf("Enter Page Size (bytes): ");
    scanf("%lld", &page_size);


    int page_offset_bits = (int)log2(page_size);
    
    int page_num_bits = (int)logical_addr_bits - page_offset_bits;
    
    long long total_frames = main_mem_size / page_size;
    
    int frame_num_bits = (int)log2(total_frames);
    
    int physical_addr_bits = frame_num_bits + page_offset_bits;
    
    long long total_pages_las = pow(2, page_num_bits);

    printf("\n--- RESULTS ---\n");
    printf("1. Logical Address Bits = %lld\n", logical_addr_bits);
    printf("2. Page Number Bits = %d\n", page_num_bits);
    printf("3. Page Offset bits = %d\n", page_offset_bits);
    printf("4. Physical Address Bits = %d\n", physical_addr_bits);
    printf("5. frame number bits = %d\n", frame_num_bits);
    printf("6. frame offset bits = %d\n", page_offset_bits); 
    printf("7. Total number of pages in the Logical Address Space = %lld\n", total_pages_las);
    printf("8. Total Number of frames can be allocated in Main memory (MM) = %lld\n", total_frames);

    return 0;
}