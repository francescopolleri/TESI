import numpy as np

test = np.array([2,3,5,8,10,9,10,8,0,6,8,9])
bin=[]

all_entries_less_than_8=True
for x in test:
    if x>=8:
        all_entries_less_than_8=False

if(all_entries_less_than_8==True):
    print('all entries less than 8')



for i in range(len(test)):
    if (test[i]>=8):
        bin.append(i)



if (len(bin)==1):
    print('un solo valore')
    th=bin[i]
    print(th)

else:
    sequences=[]
    curr_seq=[bin[0]]
    for i in range (1,len(bin)):
        if bin[i] == bin[i-1]+1:
            curr_seq.append(bin[i])
        else:
            sequences.append(curr_seq)
            curr_seq=[bin[i]]

if curr_seq:
    sequences.append(curr_seq)

longest_sequence = max(sequences, key=len)

print(sequences)
print(longest_sequence)

