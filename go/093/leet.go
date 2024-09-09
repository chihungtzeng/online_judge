package leet

import "strconv"

// import "fmt"

func restoreIpAddresses(s string) []string {
	ips := make([]string, 0, 8)
	if len(s) > 12 || len(s) == 0 {
		return ips
	}
	addr := []string{string(s[0]), "", "", ""}
	ips = _solve(ips, addr, s[1:], 0)
	return ips
}

func _solve(ips []string, addr []string, s string, kth int) []string {
	if kth >= 4 {
		return ips
	}
	if len(s) == 0 {
		if kth == 3 && addr[3] != "" {
			ip := addr[0] + "." + addr[1] + "." + addr[2] + "." + addr[3]
			ips = append(ips, ip)
		}
		return ips
	}
	alen := len(addr[kth])
	//	fmt.Printf("addr=%v, kth=%d, s=%s\n", addr, kth, s)
	if alen <= 2 && addr[kth][0] != '0' {
		concat_s := addr[kth] + string(s[0])
		atoi, _ := strconv.Atoi(concat_s)
		if atoi <= 255 {
			org := addr[kth]
			addr[kth] = concat_s
			ips = _solve(ips, addr, s[1:], kth)
			addr[kth] = org
		}
	}
	if kth < 3 {
		kth += 1
		addr[kth] += string(s[0])
		ips = _solve(ips, addr, s[1:], kth)
		addr[kth] = ""
		kth -= 1
	}
	return ips
}
