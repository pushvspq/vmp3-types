#pragma once

#include <cstdint>

namespace vmp::types {
	//
	// CRC info structure used to verify the CRC hash of a file
	//
	struct crc_info_t {
		uint32_t address; // RVA to data
		uint32_t size; // Size of data
		uint32_t hash; // Calculated hash of data
	};

	//
	// Helper file CRC info structure
	//
	struct file_crc_info_t {
		uint32_t size; // Size of file
	};

	//
	// Section info structure used to fix memory protection(s)
	//
	struct section_info_t {
		uint32_t address; // RVA to section
		uint32_t size; // Size of section
		uint32_t type; // Protection type
	};

	//
	// Packer info structure used to unpack section(s)
	// 'dst' became XOR-encrypted since VMProtect 3.9.5
	//
	struct packer_info_t {
		uint32_t src; // RVA to LZMA packed content
		uint32_t dst; // RVA to packed section
	};

	//
	// DLL info structure used to resolve import(s)
	//
	struct dll_info_t {
		uint32_t name; // RVA to encrypted string
	};

	//
	// Import info structure used to resolve a given import
	//
	struct import_info_t {
		uint32_t name; // RVA to encrypted string / Ordinal of import
		uint32_t address; // RVA to address location

		int32_t key; // Key used to encrypt import
	};

	//
	// IAT info structure used to copy the import table if import protection is disabled
	//
	struct iat_info_t {
		uint32_t src; // RVA to resolved import table
		uint32_t dst; // RVA to copy
		uint32_t size; // Size of IAT
	};

	//
	// Fixup entry structure used to resolve relocations, etc.
	//
	struct fixup_entry_t {
		uint16_t offset : 12; // Offset in page to relocate
		uint16_t type : 4; // Type of relocation
	};

	//
	// Fixup info structure used to resolve relocations, etc.
	//
	struct fixup_info_t {
		uint32_t address; // RVA to page
		uint32_t size; // Size of block / used to calculate count of entries - ( fixup_info->size - 8 ) >> 1
	};

	//
	// Relocation info structure prepared for ELF, Mach-o
	//
	struct reloc_info_t {
		uint32_t address; // RVA of address
		uint32_t src; // RVA of SRC
		uint32_t type; // Type of relocation
	};
} // namespace vmp::types