ENTRY(mikoto_kernel_start)

SECTIONS
{
	. = 0x10000;
	.text : {
		*(.entry);
		*(.text, rodata);
	}

	.data : {
		*(.data);
	}

	.bss : {
		*(.bss);
	}

	.stack : {
		. = . + 0x1000;
		. = ALIGN(4);
		stack_top = .;
		. = . + 0x1000;
		. = ALIGN(4);
		irq_stack_top = .;
	}
}

