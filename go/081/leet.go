package leet

func search(nums []int, target int) bool {
	return trim_search(nums, target, 0, len(nums))
}

func trim_search(nums []int, target int, left int, right int) bool {
	nelem := right - left
	if nelem == 0 {
		return false
	}
	if nelem == 1 {
		return bool(target == nums[left])
	}
	last := nums[right-1]
	if nums[left] < last && (target < nums[left] || target > last) {
		return false
	}
	mid := left + nelem/2
	return trim_search(nums, target, left, mid) || trim_search(nums, target, mid, right)
}
