import hashlib

# p = 
q = 794137
# g = 

# m_1 = "IOU $1000"
# m_2 = "Merry Christmas"
# r_1 = r_2 = 916128381002192237330415624031916695461722389304

# s_1 = 1016140177410528212949844490506968808343879600370
# s_2 = 767135282992918681484216676594223285185365265436

hash_object = hashlib.sha1(b'Desne tajna zprava %d' % 1)
hm1 = int(hash_object.hexdigest(), 16)
print(hm1)
hmm1 = hm1 % q
cnt = 2
while True:
	hash_object = hashlib.sha1(b'Desne tajna zprava %d' % cnt)
	hm2 = int(hash_object.hexdigest(), 16)
	hmm2 = hm2 % q

	if hmm1 == hmm2:
		print('Desne tajna zprava %d' % cnt)
		break
	cnt += 1

