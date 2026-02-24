
# int128

normally we have 32 and 64 bit integers
avaliable to us. Sometimes though we
want larger integers, like 128, or 256,
or even larger :).    
    
Here we will impliment an integer double
the size of the long type, 128 bits. I will
note that gcc and clang already provide this
type through the __int128_t extension. This
is a more cross-platform way to do it though.    
     
With these methods, do what is simple first
and don't worry about it. The point is to
be thinking about how these operations are even
done in the first place.
