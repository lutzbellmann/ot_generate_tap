# ot_generate_tap

Generates a **TAP (Thread Attestation Passcode)** — a 9-digit one-time passcode used for credential sharing in the [Thread 1.4](https://www.threadgroup.org/) protocol.

## What it does

The tool generates a random 8-digit numeric string and appends a [Verhoeff check digit](https://en.wikipedia.org/wiki/Verhoeff_algorithm), producing a 9-digit TAP. The Verhoeff algorithm provides strong single-digit error detection, catching all single-digit errors and adjacent transpositions.

## Build

```sh
cc -o ot_generate_tap ot_generate_tap.c
```

## Usage

```sh
./ot_generate_tap
```

Example output:

```
Generating TAP or "One Time Passcode" for Thread 1.4 credential sharing
(c) 2026, Dr. Lutz Bellmann
Generated TAP: 583920417
```

## Files

| File | Description |
|------|-------------|
| [ot_generate_tap.c](ot_generate_tap.c) | Main source: TAP generation logic and entry point |
| [verhoeff_tables.h](verhoeff_tables.h) | Verhoeff algorithm lookup tables (multiplication, permutation, inverse) |

## TAP format

- **8 random digits** — generated from `rand()` seeded with the current time
- **1 Verhoeff check digit** — appended as the 9th digit
- **Total: 9 digits**

## License

MIT — see [LICENSE](LICENSE)
