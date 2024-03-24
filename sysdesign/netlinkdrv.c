#include <linux/module.h>
#include <linux/netlink.h>

#define NETLINK_USER 31

struct sock *nl_sk = NULL;

void nl_recv_msg(struct sk_buff *skb) {
	struct nlmsghdr *nlh;
	int pid;
	struct sk_buff *skb_out;
	int msg_size;
	char *msg = "Hello from kernel";
	int res;

	nlh = (struct nlmsghdr *)skb->data;
	printk(KERN_INFO "Netlink received message: %s\n", (char *)NLMSG_DATA(nlh));

	pid = nlh->nlmsg_pid; /*pid of sending process */

	msg_size = strlen(msg);
	skb_out = nlmsg_new(msg_size, 0);
	if (!skb_out) {
		printk(KERN_ERR "Failed to allocate new skb\n");
		return;
	}

	nlh = nlmsg_put(skb_out, 0, 0, NLMSG_DONE, msg_size, 0);
	NETLINK_CB(skb_out).dst_group = 0; /* not in multicast group */
	strncpy(nlmsg_data(nlh), msg, msg_size);

	res = nlmsg_unicast(nl_sk, skb_out, pid);
	if (res < 0)
		printk(KERN_INFO "Error while sending back to user\n");
}

int __init init_module() {
	struct netlink_kernel_cfg cfg = {
		.input = nl_recv_msg,
	};

	nl_sk = netlink_kernel_create(&init_net, NETLINK_USER, &cfg);
	if (!nl_sk) {
		printk(KERN_ALERT "Error creating socket.\n");
		return -10;
	}

	printk(KERN_INFO "Kernel module initialized\n");
	return 0;
}

void __exit cleanup_module() {
	printk(KERN_INFO "Kernel module exiting\n");
	netlink_kernel_release(nl_sk);
}
