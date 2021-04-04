#ifndef _FONT_H
#define _FONT_H

union FontData {
  uint64_t data;
  uint8_t line[7];
  uint8_t kerning;
};

class Font {
 public:
  Font() {}

  const FontData &getFont(char c) const {
    return _font[c - 0x20];
  }

  const FontData _font[104] = {
    { .data = 0x0000000000000002 },
    { .data = 0x0c000c0c1e1e0c06 }, // !
    { .data = 0x0000000014363607 }, // "
    { .data = 0x6c6cfe6cfe6c6c08 }, // #
    { .data = 0x081e201c023c0807 }, // $
    { .data = 0x60660c1830660608 }, // %
    { .data = 0xfc66a6143c663c08 }, // &
    { .data = 0x000000060c0c0c05 }, // '
    { .data = 0x180c0606060c1806 }, // (
    { .data = 0x060c1818180c0606 }, // )
    { .data = 0x006c38fe386c0008 }, // *
    { .data = 0x0008083e08080007 }, // +
    { .data = 0x060c0c0c00000005 }, // ,
    { .data = 0x0000001e00000006 }, // -
    { .data = 0x0606000000000004 }, // .
    { .data = 0x00060c1830600008 }, // /
    { .data = 0x3c66666e76663c08 }, // 0
    { .data = 0x7e1818181c181808 },
    { .data = 0x7e060c3060663c08 },
    { .data = 0x3c66603860663c08 },
    { .data = 0x30307e3234383008 },
    { .data = 0x3c6660603e067e08 },
    { .data = 0x3c66663e06663c08 },
    { .data = 0x1818183030667e08 },
    { .data = 0x3c66663c66663c08 },
    { .data = 0x3c66607c66663c08 }, // 9
    { .data = 0x0006060006060004 }, // :
    { .data = 0x060c0c000c0c0005 },
    { .data = 0x30180c060c183007 },
    { .data = 0x00001e001e000006 },
    { .data = 0x060c1830180c0600 },
    { .data = 0x1800183860663c07 },
    { .data = 0x003c421a3a221c08 },
    { .data = 0x6666667e66663c08 }, // A
    { .data = 0x3e66663e66663e08 },
    { .data = 0x3c66060606663c08 },
    { .data = 0x3e66666666663e08 },
    { .data = 0x7e06063e06067e08 },
    { .data = 0x0606063e06067e08 },
    { .data = 0x3c66760606663c08 },
    { .data = 0x6666667e66666608 },
    { .data = 0x3c18181818183c06 }, // I
    { .data = 0x1c36363030307807 },
    { .data = 0x66361e0e1e366608 },
    { .data = 0x7e06060606060608 },
    { .data = 0xc6c6c6d6feeec608 },
    { .data = 0xc6c6e6f6decec608 },
    { .data = 0x3c66666666663c08 },
    { .data = 0x06063e6666663e08 },
    { .data = 0x603c766666663c08 },
    { .data = 0x66361e3e66663e08 },
    { .data = 0x3c66603c06663c08 },
    { .data = 0x18181818185a7e08 },
    { .data = 0x7c66666666666608 },
    { .data = 0x183c666666666608 },
    { .data = 0xc6eefed6c6c6c608 },
    { .data = 0xc6c66c386cc6c608 },
    { .data = 0x1818183c66666608 },
    { .data = 0x7e060c1830607e08 }, //  Z
    { .data = 0x1e06060606061e06 }, //  [
    { .data = 0x0002060C18302006 }, // backslash
    { .data = 0x0000007F7F414108 }, //  ]
    { .data = 0x0810204020100808 }, //  ^
    { .data = 0x7e00000000000008 }, //  _
    { .data = 0x000000060c0c0c05 }, //  `
    { .data = 0x7c667c603c000008 }, //  a
    { .data = 0x3e66663e06060608 },
    { .data = 0x3c6606663c000008 },
    { .data = 0x7c66667c60606008 },
    { .data = 0x3c067e663c000008 },
    { .data = 0x0c0c3e0c0c6c3808 },
    { .data = 0x3c607c66667c0008 },
    { .data = 0x6666663e06060608 },
    { .data = 0x1e0c0c0c000c0006 }, // i
    { .data = 0x1c36363030003007 },
    { .data = 0x66361e3666060608 },
    { .data = 0x0606060606060604 }, // l
    { .data = 0xd6d6feeec6000008 },
    { .data = 0x6666667e3e000008 },
    { .data = 0x3c6666663c000008 },
    { .data = 0x06063e66663e0008 },
    { .data = 0xf0b03c36363c0008 },
    { .data = 0x060666663e000008 },
    { .data = 0x3e403c027c000008 },
    { .data = 0x1818187e18180008 },
    { .data = 0x7c66666666000008 },
    { .data = 0x183c666600000008 },
    { .data = 0x7cd6d6d6c6000008 },
    { .data = 0x663c183c66000008 },
    { .data = 0x3c607c6666000008 },
    { .data = 0x1e060c181e000006 }, // z
    { .data = 0x380c0c060c0c3807 }, // {
    { .data = 0x0202020202020203 }, // |
    { .data = 0x0000083E77414107 }, // }
    { .data = 0x0010081810180808 }  // ~
  };
};

#endif
