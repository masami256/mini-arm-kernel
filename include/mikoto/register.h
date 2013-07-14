#ifndef __MIKOTO_REGISTER_H
#define __MIKOTO_REGISTER_H

#define read_control_register(reg_name, ret) \
	do { \
		__asm__("mrc p15, 0, %[Rd], reg_name, c0, 0;\n\t" \
			: \
			: [Rd] "=r"(ret) \
			); \
	} while(0)

#define write_control_register(reg_name, data) \
	do { \
		__asm__("mcr p15, 0, %[Rd], reg_name, c0, 0;\n\t" \
				: [Rd] "r"(data) \
				: \
			   ); \
	} while(0)

#endif // __MIKOTO_REGISTER_H
