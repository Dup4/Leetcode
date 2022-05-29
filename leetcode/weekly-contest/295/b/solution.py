from calendar import c


class Solution:
    def discountPrices(self, sentence: str, discount: int) -> str:
        strl = sentence.split(' ')

        for i in range(len(strl)):
            if (strl[i][0] != '$'):
                continue

            try:
                a = int(strl[i][1:])
                if str(a) == strl[i][1:]:
                    strl[i] = '$' + ("%.2f" % (a - (a * discount / 100)))
                continue
            except ValueError:
                pass

            try:
                b = float(strl[i][1:])
                if str(b) == strl([i][1:]):
                    strl[i] = '$' + ("%.2f" % (a - (a * discount / 100)))
            except ValueError:
                pass

        return " ".join(strl)
