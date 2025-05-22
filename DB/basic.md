Sure! Here's a clean and crisp **Markdown version** of the explanation for your notes:

---

# 📘 SQLAlchemy Eager Loading

## 🔄 What is Eager Loading?

Eager loading in SQLAlchemy is a way to **preload related data** in advance, using fewer queries. It helps avoid the **N+1 query problem**.

---

## ❗ N+1 Query Problem

Without eager loading:

```python
packages = session.query(Package).all()

for pkg in packages:
    print(pkg.partner.name)  # Hits DB each time
```

- 1 query for all packages + N queries for partners = **1 + N total queries**

With eager loading:

```python
from sqlalchemy.orm import joinedload

packages = session.query(Package).options(joinedload(Package.partner)).all()
```

- Only **1 query**. Related data is preloaded.

---

## ⚙️ Types of Eager Loading

| Method           | Description                            | Use Case                          |
|------------------|----------------------------------------|-----------------------------------|
| `joinedload()`   | Uses SQL JOIN                          | One-to-one / one-to-few           |
| `selectinload()` | Uses separate query with `WHERE IN`    | One-to-many / many-to-many        |
| `subqueryload()` | Uses a subquery                        | Similar to `selectinload()`       |

---

## ✅ When to Use

- You **know** you'll access related objects
- You want to **reduce DB hits**
- To **prevent the N+1 query problem**

---

## 🔍 Examples

### `joinedload`

```python
from sqlalchemy.orm import joinedload

session.query(Package).options(joinedload(Package.partner)).all()
```

### `selectinload`

```python
from sqlalchemy.orm import selectinload

session.query(Package).options(selectinload(Package.partner)).all()
```

---

Let me know if you want a real working example with models like `Package`, `Partner`, and `PackageCost`!