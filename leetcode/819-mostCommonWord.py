import re

class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        paragraph = re.sub(r"[!?',;.]", " ", paragraph)
        tokens = paragraph.split(' ')

        tokenDict = dict()
        for token in tokens:
            if token == "":
                continue

            token = token.lower()

            if not token in banned:
                if not token in tokenDict:
                    tokenDict[token] = 1
                else:
                    tokenDict[token] = tokenDict[token] + 1


        maxToken = ""
        maxFrequency = 0
        for key, value in tokenDict.items():
            frequency = value
            if maxFrequency < value:
                maxFrequency = value
                maxToken = key

        return maxToken