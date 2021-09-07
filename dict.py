        hashTable = {}
        for a in nums1:
            for b in nums2:
                if a+b not in HashTable:  # 也可以if HashTable.get(a+b) == None:  HashTable(a+b)=1 #也可一if a+b not in HashTable.keys():
                    HashTable[a+b] = 0
                HashTable[a+b] += 1
