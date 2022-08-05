# PyroDist
# Language: C++
# Input: TXT
# Output: TXT
# Tested with: PluMA 1.1, GCC 4.8.4
# Dependencies: AmpliconNoise 1.29

PluMA plugin to compute distance matrix from flowgrams using PyroDist (Quince et al, 2011).

The plugin accepts as input a TXT file of tab-delimited keyword-value pairs:
flowfile: Flowgrams
lookupfile: DAT file for database

Matrix is output in TXT format (1 element per line).
