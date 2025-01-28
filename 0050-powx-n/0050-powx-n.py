class Solution(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        if n == 0:
            return 1
        elif n < 0:
            x = 1 / x
            n = -n
        
        result = 1
        while n:
            if n % 2:  # If n is odd
                result *= x
            x *= x  # Square the base
            n //= 2  # Halve the exponent
        
        return result
