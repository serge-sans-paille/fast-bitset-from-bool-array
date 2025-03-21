Fast Bitset from Array of Boolean
=================================

This repo contains a single file ``tobitset.c`` showing how to convert an array of 8 booleans
into a bitset stored in a single byte, using only a 64 bit multiplication and a
bit shift. It is a fast yet portable alternative to:

.. code-block:: c

    unsigned char tobitset(unsigned char unpacked[8]) {
        unsigned char res = 0;
        for(int i = 0; i < 8; ++i)
            res += unpacked[i] << i;
        return res;
    }

assuming each element of ``unpacked`` holds the value of ``0`` or ``1``.

It can be used to quickly initialize a bitset without branch, loop nor special hardware support.

It's somehow similar to `_mm_movemask_epi8
<https://www.intel.com/content/www/us/en/docs/intrinsics-guide/index.html#ig_expand=4634,2251,5966,5930,116,6633,4288,116,5894,6088,6130,6088,5839,4634,4602&techs=SSE_ALL&text=_mm_movemask_epi8>`_
with the notable exception that ``_mm_movemask_pi8`` honors the most
significant bit and ``tobitset`` honors the least significant bit.

Contact
-------

Serge « sans paille » Guelton <sergesanspaille@free.fr>
