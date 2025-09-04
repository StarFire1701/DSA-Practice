int xz = abs(x - z);
    int yz = abs(y - z);
    if (xz == yz) return 0;
    return xz < yz ? 1 : 2;