#ifndef __MIKOTO_REGISTER_H
#define __MIKOTO_REGISTER_H

#define read_control_register_c1(ret) \
	do { \
		__asm__("mrc p15, 0, %[Rd], c1, c0, 0;\n\t" \
			: \
			: [Rd] "r"(ret) \
			); \
	} while(0)

#define write_control_register_c1(data) \
	do { \
		__asm__("mcr p15, 0, %[Rd], c1, c0, 0;\n\t" \
				: [Rd] "=r"(data) \
				: \
			   ); \
	} while(0)

#define read_control_register_c2(ret) \
	do { \
		__asm__("mrc p15, 0, %[Rd], c2, c0, 0;\n\t" \
			: \
			: [Rd] "r"(ret) \
			); \
	} while(0)

#define write_control_register_c2(data) \
	do { \
		__asm__("mcr p15, 0, %[Rd], c2, c0, 0;\n\t" \
				: [Rd] "=r"(data) \
				: \
			   ); \
	} while(0)

#endif // __MIKOTO_REGISTER_H
