# Contributing evidence

Every new finding should include:

1. Board revision and device identifier used for the test.
2. Exact test equipment and probe configuration.
3. Power state and firmware version.
4. Raw capture or photograph, not only a summary.
5. A SHA-256 digest for binary evidence.
6. Clear separation between observation, inference, and speculation.

Use filenames beginning with UTC time where practical:

```text
20260719T213500Z-jp1-coldboot-115200-8n1.log
```

Never commit credentials, private keys, unredacted configuration backups, or personally identifying device labels to a public fork.
