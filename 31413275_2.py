lfrom urllib.request import urlopen
from bs4 import BeautifulSoup
import string
import collections
import re

text = ''
noPunct = ''
res_final = []

print('\nProcessing URL ending with:')

#extracts all the words from every wikipedia entry
for i in string.ascii_uppercase:
    for j in string.ascii_uppercase:
        print('[{}{}] '.format(i, j), end='', flush=True)
        url = 'https://en.wikipedia.org/wiki/{}{}'.format(i, j)
        html = urlopen(url).read()
        soup = BeautifulSoup(html, features="html.parser")
        for element in soup(["script", "style"]):
            element.extract()
        text = soup.get_text()
        res = re.findall('[A-Za-z][a-z]+|a', text)
        res_final.extend(res)

#outputs the top 15
print('\n')
ctr = collections.Counter(res_final)
for i in ctr.most_common(15):
    (v, k) = i
    print('{1}  {0:15}'.format(v, k))
