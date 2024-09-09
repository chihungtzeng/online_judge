package leet

type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseBetween(head *ListNode, m int, n int) *ListNode {
	if m == n {
		return head
	}
	var ftail, mhead, mtail, rhead, cur, prev, next *ListNode
	cur = head
	nvisit := 0
	for cur != nil {
		nvisit += 1
		next = cur.Next
		if nvisit == m {
			ftail = prev
			mtail = cur
		}
		if nvisit == n {
			mhead = cur
			rhead = cur.Next
		}

		if nvisit > m && nvisit <= n {
			next = cur.Next
			cur.Next = prev
		}
		prev = cur
		cur = next
	}
	if mtail != nil {
		mtail.Next = rhead
	}
	if ftail != nil {
		ftail.Next = mhead
	}
	if m == 1 {
		return mhead
	} else {
		return head
	}
}
