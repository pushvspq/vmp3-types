#pragma once

#include <cstdint>

namespace vmp3 {
	inline constexpr std::uint8_t LZMA_PROPS[ ] = "\x5D\x00\x00";
	inline constexpr std::uint32_t LZMA_PROPS_SIZE = 3;

	//
	// CMP BYTE PTR SS:[EBP+0x08],0x00
	//
	inline constexpr std::uint8_t WIN_X86_LOADER_STRCMP[ ] = "\x80\x7D\x08\x00";
	inline constexpr std::uint32_t WIN_X86_LOADER_STRCMP_SIZE = 4;

	//
	// SUB RSP,0x20
	//
	inline constexpr std::uint8_t WIN_X64_LOADER_STRCMP[ ] = "\x48\x83\xEC\x20";
	inline constexpr std::uint32_t WIN_X64_LOADER_STRCMP_SIZE = 4;

	//
	// CMP DWORD PTR DS:[RAX+RCX],0x4550
	//
	inline constexpr std::uint8_t WIN_X64_LOADER_GETPROCADDRESS[ ] = "\x81\x3C\x08\x50\x45\x00\x00";
	inline constexpr std::uint32_t WIN_64_LOADER_GETPROCADDRESS_SIZE = 7;

	struct crc_info_t {
		uint32_t address;
		uint32_t size;
		uint32_t hash;
	};

	struct file_crc_info_t {
		uint32_t size;
	};

	struct section_info_t {
		uint32_t address;
		uint32_t size;
		uint32_t type;
	};

	struct packer_info_t {
		uint32_t src;
		uint32_t dst;
	};

	struct dll_info_t {
		uint32_t name;
	};

	struct import_info_t {
		uint32_t name;
		uint32_t address;

		int32_t key;
	};

	struct iat_info_t {
		uint32_t src;
		uint32_t dst;
		uint32_t size;
	};

	struct fixup_entry_t {
		uint16_t offset : 12;
		uint16_t type : 4;
	};

	struct fixup_info_t {
		uint32_t address;
		uint32_t size;
	};

	struct reloc_info_t {
		uint32_t address;
		uint32_t src;
		uint32_t type;
	};
} // namespace vmp3