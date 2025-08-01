
To list all namespaces in your Kubernetes cluster using `kubectl`, just run:

bash

describe pod

kubectl describe pod <pod-name>

CopyEdit

`kubectl get namespaces`
### To see the directory of server
kubectl exec -it bifrost-inbound-integration-service-8d5f7d574-c5vg5   -- /bin/bash
exit 
### To get the pods 
kubectl get pods | grep inbound

### To see logs 
kubectl logs -f corporate-authentication-service-668479d947-9p7lg

### To see logs of multiple pods

kubectl -n jio-bhaaratai-covid logs -f -l app.kubernetes.io/instance=jhh-partner-service --tail 100 --max-log-requests 12 

kubectl logs -f -l app=pme-service-listing --tail 100 --max-log-requests 12



kubectl logs -f -l app=bifrost-protocol-mapper-service --max-log-requests 12

kubectl get pods --show-labels
### **kubectl**:

- This is the command-line tool for interacting with Kubernetes clusters.

### 2. **-n jio-bhaaratai-covid**:

- The `-n` flag specifies the namespace in Kubernetes. In this case, it’s selecting the `jio-bhaaratai-covid` namespace, which is like a project or isolated environment within Kubernetes.

### 3. **logs -f**:

- The `logs` command retrieves logs from Kubernetes pods.
- `-f` is short for "follow." It allows you to continuously view new log entries as they are generated, like a live stream.

### 4. **-l app.kubernetes.io/instance=jiohealthhub-patient-consult-booking**:

- The `-l` flag lets you filter pods by labels. Here, it’s filtering for pods with the label `app.kubernetes.io/instance=jiohealthhub-patient-consult-booking`. This helps you target specific services or applications by name.

### 5. **--tail 330**:

- This specifies that only the last 330 log lines should be shown. This can be useful for reducing clutter, especially if you don’t need to see all logs, just the latest.

### 6. **--max-log-requests 1123**:

- Limits the number of log requests across multiple pods to 1123, which can be useful in high-traffic systems.

### 7. **| grep -A10 -B10 "get_all_slots"**:

- The `|` symbol pipes the log output to another command, `grep`.
- `grep` searches for lines containing `"get_all_slots"` and outputs them.
- `-A10` means to show 10 lines _after_ each match.
- `-B10` means to show 10 lines _before_ each match.
- This way, you get a bit of context around each occurrence of "get_all_slots."

 